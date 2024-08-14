#ifndef TIMER_H
#define TIMER_H

#include <thread>


class SimpleTimer {
    public:
        /**
         * Creates a timer object
         * 
         * This object will start a new thread that sleeps for the desired number of milliseconds
         * A function is run after the desired number of ms have elapsed
         * 
         * ms, func, args
         */
        SimpleTimer(int milliseconds, void (*func));
        ~SimpleTimer();

    private:
};
#endif