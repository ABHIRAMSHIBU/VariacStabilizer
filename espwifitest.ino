#include <ESP8266WiFi.h>

String ssid =  "WiFi";
String pass =  "anme9537";

class Timer
{
private:
    unsigned long (*getTime)(void) = {};
    unsigned long time = {};
    const unsigned long MAX_TIME = -1;
    bool usingMillis = {};
public:
    ~Timer()
    {
    }

    Timer(bool useMillis)
    {
        if(useMillis){
            getTime = &millis;
            usingMillis = true;
        }
        else{
            getTime = &micros;
            usingMillis = false;
        }
    }
    
    bool start(){
        if(time==0){
            time = getTime();
            return true;
        }
        else{
            return false;
        }
    }

    unsigned long currentElapsed(){
        unsigned long timeDelta;
        if(time>getTime()){ // Probably timer overflowed
            timeDelta = MAX_TIME - time + getTime();
        }
        else{
            timeDelta = getTime() - time;
        }
        return timeDelta;
    }

    unsigned long end(){
        unsigned long timeDelta = currentElapsed();
        time = 0;
        return timeDelta;
    }

    double toSeconds(){
        unsigned long timeDelta = currentElapsed();
        double timeInSec = 0;
        if(usingMillis){
            timeInSec = timeDelta/1000;
        }
        else{
            timeInSec = (timeDelta/(1000*1000));
        }
        return timeInSec;
    }
};

class WiFiManager {
  String ssid="";
  String password="";
  bool status{};
  bool ap_mode{};

  unsigned long default_timeout=3000;
  Timer timer{true};

  public:
  WiFiManager(bool ap_mode, String ssid, String password,bool wait_for_connection=false):ssid{ssid},password{password},ap_mode{ap_mode}{
    timer.start();
    // mode: true AP Mode, False: Client Mode
    if(!ap_mode){
        WiFi.begin(ssid, pass);
        if(wait_for_connection){
          status = waitForConnection();
        }
    }
    else{
        WiFi.softAP(ssid, password);
        if(wait_for_connection){
          status = waitForConnection();
        }
    }

  }


  bool waitForConnection(){
    if(!ap_mode){
          while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
            if(timer.currentElapsed()>default_timeout){
              timer.end();
              break;
            }
          }
          return true;
    }
    else{
        while (WiFi.softAPgetStationNum() == 0) 
          {
            delay(500);
            Serial.print(".");
            if(timer.currentElapsed()>default_timeout){
              timer.end();
              break;
            }
          }
          return true;
      return false;
    }
  }

  bool getStatus(){
    return status;
  }




};
 
void setup() 
{
      Serial.begin(9600);
      delay(10);
                
      Serial.println("Connecting to ");
      Serial.println(ssid); 

      WiFiManager wifimanager{true,ssid,pass,true};
      Serial.println("");
      Serial.println("WiFi connected"); 
}
 
void loop() 
{      
  
}
