#include "timer.h"

class Timer {
    public:
        long long int startTime = 0;
        Timer(int milliseconds) {
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




