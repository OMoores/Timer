#include "timer.h"


/**
 * Creates a timer object runs a function after a certain amount of time has elapsed
 */
class SimpleTimer {
    long long int startTime = 0;
    public:
        long long int startTime = 0;

        /**
         * Creates a timer object
         * 
         * This object will start a new thread that sleeps for the desired number of milliseconds
         * A function is run after the desired number of ms have elapsed
         * 
         * ms, func, args
         */
        SimpleTimer(int milliseconds, void (*func)()) {
            startTimer(milliseconds);
        }
        void startTimer(int milliseconds) {
            std::thread thread_obj(sleepThread, milliseconds);
            startTime = getTimeSinceEpochMS();
        }
        long long int getTimePassed() {
            long long int timePassed = startTime - getTimeSinceEpochMS();
            return timePassed;
        }
    private:
        void sleepThread(int milliseconds) {
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }
        /**
         * Gets time since epoch in milliseconds
         */
        int getTimeSinceEpochMS() {
            long long int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            return time;
        }
        
};

