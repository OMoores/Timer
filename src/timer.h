#ifndef TIMER_H
#define TIMER_H

#include <thread>




class SimpleTimer {
    public:
        long long int startTime = 0;
        void (*timerFunc)();
        /** Initiallises the timer and starts it, will run func when it expires */
        SimpleTimer(int milliseconds, void (*func)());
        ~SimpleTimer();
        void startTimer(int milliseconds, void (*func)());
        long long int getTimePassed();
    private:
        std::thread timerThread;
        void sleepThread(int milliseconds, void (*func)());
        int getTimeSinceEpochMS();

};

#endif