#ifndef STEPPER_H
#define STEPPER_H

/*
    This class defines timings for the game loop

    Terminal uses thread sleep which shouldn't be a
    problem if it's not a time critical game
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
    Stepper(Type, double update, double render);
    ~Stepper();

    // TODO inline
    bool isTimeToUpdate();
    bool isTimeToRender();

    void updateFinished();
    void renderFinished();

    void letSleep();

    unsigned long getUpdateSteps() { return updateSteps; }
    unsigned long getRenderSteps() { return renderSteps; }

    void paused();
    void exit();

    Stepper(const Stepper&);
    Stepper & operator = (const Stepper &);

protected:
    

private:
    Type type = Type::NORMAL;
    // FIXME type correct?
    unsigned long updateSteps = 0;
    unsigned long renderSteps = 0;
    unsigned long updateRate; // nanoseconds
    unsigned long renderRate; // nanoseconds

    // Update
    std::chrono::high_resolution_clock::time_point currentTime_u;
    std::chrono::high_resolution_clock::time_point lastTime_u;
    std::chrono::high_resolution_clock::duration diff_u;

    // Render
    std::chrono::high_resolution_clock::time_point currentTime_r;
    std::chrono::high_resolution_clock::time_point lastTime_r;
    std::chrono::high_resolution_clock::duration diff_r;

    // Sleep
    std::chrono::high_resolution_clock::time_point sleep_to_u;
    std::chrono::high_resolution_clock::duration sleep_diff_u;
    
    std::chrono::high_resolution_clock::time_point sleep_to_r;
    std::chrono::high_resolution_clock::duration sleep_diff_r;
};

#endif /* STEPPER_H */