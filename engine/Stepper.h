#ifndef STEPPER_H
#define STEPPER_H

/*
    This class defines timings for the game loop
*/

#include <chrono>

class Stepper
{
public:
    enum class Type
    {
        NORMAL,
        TERMINAL
    };

    // type, updates per sec, render per sec
    // PERHAPS mins if too fast for terminal
    Stepper(Type, int, int);
    ~Stepper();

    // TODO inline
    bool isTimeToUpdate();
    bool isTimeToRender();

    void updateFinished();
    void renderFinished();

    void paused();
    void exit();

    Stepper(const Stepper&);
    Stepper & operator = (const Stepper &);

protected:
    

private:
    Type type = Type::NORMAL;
    unsigned long steps = 0;
    unsigned long updateRate; // nanoseconds
    unsigned long renderRate; // nanoseconds

    std::chrono::high_resolution_clock::time_point currentTime;
    std::chrono::high_resolution_clock::time_point lastTime;
    std::chrono::high_resolution_clock::time_point diff;
};

#endif /* STEPPER_H */