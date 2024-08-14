#include <thread>

/**
 * Creates a timer object runs a function after a certain amount of time has elapsed
 */
class SimpleTimer {
    public:
        long long int startTime = 0;

        /**
         * Creates a simple timer object that will run a function after a certain amount of time
         */
        SimpleTimer(int milliseconds, void (*func)()) {
            //startTimer(milliseconds, func);
        }

        ~SimpleTimer() {
            if (timerThread.joinable()) {
                timerThread.join();
            }
        }


        void startTimer(int milliseconds, void (*func)()) {
            // Creates a thread which sleeps for requested number of seconds
            timerThread = std::thread(SimpleTimer::sleepThread, this, milliseconds);
            startTime = getTimeSinceEpochMS();
        }
        long long int getTimePassed() {
            long long int timePassed = startTime - getTimeSinceEpochMS();
            return timePassed;
        }
    private:
        /** A thread variable to store timer thread, created here so can be joined in destructor */
        std::thread timerThread;
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

