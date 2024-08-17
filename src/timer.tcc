#pragma once

#include "timer.h"

template <typename funcReturnType, typename... Args>
SimpleTimer<funcReturnType, Args...>::SimpleTimer(int milliseconds, funcReturnType (*func)(Args... args), Args... args) {
    //startTimer(milliseconds, func, args);
}