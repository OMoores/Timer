#pragma once

#include <thread>


/**
 * There seems to be a problem with implementing classes accross a header and a cpp file
 * need to find a way around this or just implement in header file?
 */

template <typename funcReturnType, typename... Args>
class SimpleTimer {
    public:
        funcReturnType result;
        bool returned = false; // If timer has finised and result set then this is true
        long long int startTime = 0; // Time since epoch timer started at
        
        /** Initiallises the timer and starts it, will run func when it expires */
        SimpleTimer(int milliseconds, funcReturnType (*func)(Args... args), Args... args);

        ~SimpleTimer();

        void startTimer(int milliseconds, funcReturnType (*func)(Args... args), Args... args);
        long long int getTimePassed();
    private:
        std::thread timerThread;
        void sleepThread(int milliseconds, funcReturnType (*func)(Args... args), Args... args);
        int getTimeSinceEpochMS();

};

#include "timer.tcc"

