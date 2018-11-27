#include <iostream>
#include <thread>

#include "Stepper.h"

Stepper::Stepper(Type type, double update, double render)
{
    // FIXME update, render only >= 0 (zero division!)

    this->type = type;

    updateRate = 1000000000 / update;
    renderRate = 1000000000 / render;
    lastTime_u = lastTime_r = std::chrono::high_resolution_clock::now();
}

Stepper::~Stepper()
{

}

// Currently only TERMINAL
// -> currentTime - lastTime >= update/sec ( 1000 / 1 = 1000) 
bool Stepper::isTimeToUpdate()
{
    if(type == Type::TERMINAL)
    {
        diff_u = std::chrono::high_resolution_clock::now()
                    - lastTime_u;

        if(std::chrono::duration <double, std::nano>(diff_u).count()
            >= updateRate)
        {
            return true;
        }
    }
    return false;
}

// TODO duplicate (another function jump wouldn't be good?)
bool Stepper::isTimeToRender()
{
    if(type == Type::TERMINAL)
    {
        diff_r = std::chrono::high_resolution_clock::now()
                    - lastTime_r;

        if(std::chrono::duration <double, std::nano>(diff_r).count()
            >= renderRate)
        {
            return true;
        }
    }
    return false;
}

void Stepper::updateFinished()
{
    lastTime_u = std::chrono::high_resolution_clock::now();
    updateSteps++;
}

void Stepper::renderFinished()
{
    lastTime_r = std::chrono::high_resolution_clock::now();
    renderSteps++;
}

void Stepper::letSleep()
{

    sleep_to_u = lastTime_u + std::chrono::nanoseconds(updateRate);
    sleep_diff_u = sleep_to_u - std::chrono::high_resolution_clock::now();

    sleep_to_r = lastTime_r + std::chrono::nanoseconds(renderRate);
    sleep_diff_r = sleep_to_r - std::chrono::high_resolution_clock::now();

    if(sleep_diff_u > sleep_diff_r)
    {
        std::this_thread::sleep_for(
            std::chrono::nanoseconds(
                sleep_diff_r
            )
        );
    }
    else
    {
        std::this_thread::sleep_for(
            std::chrono::nanoseconds(
                sleep_diff_u
            )
        );
    }
}

void Stepper::paused()
{

}

void Stepper::exit()
{

}