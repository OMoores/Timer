#pragma once

#include "timer.h"


/** Public methods */

template <typename funcReturnType, typename... Args>
SimpleTimer<funcReturnType, Args...>::SimpleTimer(int milliseconds, funcReturnType (*func)(Args... args), Args... args) {
    startTimer(milliseconds, func, args...);
}

template <typename funcReturnType, typename... Args>
SimpleTimer<funcReturnType, Args...>::~SimpleTimer() {
    if (timerThread.joinable()) {
        timerThread.join();
    }
}

template <typename funcReturnType, typename... Args>
void SimpleTimer<funcReturnType, Args...>::startTimer(int milliseconds, funcReturnType (*func)(Args... args), Args... args) {
    // Creates a thread which sleeps for requested number of seconds
    timerThread = std::thread(SimpleTimer<funcReturnType, Args...>::sleepThread, this, milliseconds, func, args...);
    startTime = getTimeSinceEpochMS();
    return;
}

template <typename funcReturnType, typename... Args>
long long int SimpleTimer<funcReturnType, Args...>::getTimePassed() {
    long long int timePassed = startTime - getTimeSinceEpochMS();
    return timePassed;
}


/** Private methods */

template <typename funcReturnType, typename... Args>
void SimpleTimer<funcReturnType, Args...>::sleepThread(int milliseconds, funcReturnType (*func)(Args... args), Args... args) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    result = func(args...);
    returned = true;
    return;
}

template <typename funcReturnType, typename... Args>
int SimpleTimer<funcReturnType, Args...>::getTimeSinceEpochMS() {
    long long int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return time;
}