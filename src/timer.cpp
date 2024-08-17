#include <timer.h>



// SimpleTimer::SimpleTimer(int milliseconds, void (*func)()) {
//     timerFunc = func;
//     startTimer(milliseconds, timerFunc);
// }

// SimpleTimer::~SimpleTimer() {
//     if (timerThread.joinable()) {
//         timerThread.join();
//     }
// }

// void SimpleTimer::startTimer(int milliseconds, void (*func)()) {
//     // Creates a thread which sleeps for requested number of seconds
//     timerThread = std::thread(SimpleTimer::sleepThread, this, milliseconds, func);
//     startTime = getTimeSinceEpochMS();
// }

// long long int SimpleTimer::getTimePassed() {
//     long long int timePassed = startTime - getTimeSinceEpochMS();
//     return timePassed;
// }

// void SimpleTimer::sleepThread(int milliseconds, void (*func)()) {
//     std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
//     func();
// }

// int SimpleTimer::getTimeSinceEpochMS() {
//     long long int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//     return time;
// }