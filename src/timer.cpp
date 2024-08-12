#include "timer.h"


/**
 * Creates a timer object runs a function after a certain amount of time has elapsed
 */
template <typename funcReturnType, typename... args>
class Timer {
    long long int startTime = 0;
    public:
        /**
         * Creates a timer object
         * 
         * This object will start a new thread that sleeps for the desired number of milliseconds
         * A function is run after the desired number of ms have elapsed
         * 
         * ms, func, args
         */
        Timer(int milliseconds) {
            
        }

        void startTimer(int milliseconds) {

        }

        long long int getTimePassed() {
        }
    private:
        
};