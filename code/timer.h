#include <chrono>
#include <stdlib.h>
#include <thread>
#include <iostream>

class Timer {
public:
    Timer(int milliseconds);
    void startTimer(int milliseconds);
    long long int getTimePassed();

private:
    long long int startTime;
    void sleepThread(int milliseconds);
    long long int getTimeSinceEpochMS();
};