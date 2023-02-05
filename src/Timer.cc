#include "Timer.hh"

Timer::~Timer(){

}

Timer::Timer(bool useMillis){
    if(useMillis){
        getTime = &millis;
        usingMillis = true;
    }
    else{
        getTime = &micros;
        usingMillis = false;
    }
}

bool Timer::start(){
    if(time==0){
        time = getTime();
        return true;
    }
    else{
        return false;
    }
}

unsigned long Timer::currentElapsed(){
    unsigned long timeDelta;
    if(time>getTime()){ // Probably timer overflowed
        timeDelta = MAX_TIME - time + getTime();
    }
    else{
        timeDelta = getTime() - time;
    }
    return timeDelta;
}

unsigned long Timer::end(){
    unsigned long timeDelta = currentElapsed();
    time = 0;
    return timeDelta;
}

double Timer::toSeconds(){
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
