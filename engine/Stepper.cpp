#include <iostream>

#include "Stepper.h"

Stepper::Stepper(Type type, int update, int render)
{
    std::cout << "Stepper constructor" << std::endl;
    std::cout << "Stepper in mode: " << static_cast<int>(type) << std::endl;

    updateRate = 1000000000 / update;
    renderRate = 1000000000 / render;
}

Stepper::~Stepper()
{
    std::cout << "Stepper deconstructor" << std::endl;
}

bool Stepper::isTimeToUpdate()
{
    if(type == Type::TERMINAL)
    {
        diff = std::chrono::high_resolution_clock::now()
                - lastTime;
        if( std::chrono::duration <double, std::nano> (diff).count()
            >= updateRate)
        {

        }
        //currentTime - lastTime  =     >=   update/sec ( 1000 / 1 = 1000) 
        //1500          100     500             1000 

    }
    return true;
}

bool Stepper::isTimeToRender()
{
    return true;
}

void Stepper::updateFinished()
{

}

void Stepper::renderFinished()
{

}

void Stepper::paused()
{

}

void Stepper::exit()
{

}