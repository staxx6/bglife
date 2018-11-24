#include <iostream>

#include "Stepper.h"

Stepper::Stepper(Type type, int upate, int render)
{
    std::cout << "Stepper constructor" << std::endl;
    std::cout << "Stepper in mode: " << static_cast<int>(type) << std::endl;
}

Stepper::~Stepper()
{
    std::cout << "Stepper deconstructor" << std::endl;
}

bool Stepper::timeToUpdate()
{
    return true;
}

bool Stepper::timeToRender()
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