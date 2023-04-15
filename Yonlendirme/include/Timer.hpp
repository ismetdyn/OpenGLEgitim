#ifndef TIMER_HPP
#define TIMER_HPP
#include <chrono>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> HighResClock;

class Timer
{
public:
    Timer();
    void start();
    double elapsedSeconds();
private:
    HighResClock m_Start;
    HighResClock m_End;
};

#endif