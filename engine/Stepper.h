#ifndef STEPPER_H
#define STEPPER_H

/*
    This class defines timings for the game loop
*/

class Stepper
{
public:
    enum class Type
    {
        NORMAL
    };

    // type, updates per sec, render per seconds
    Stepper(Type, int, int);
    ~Stepper();

    // TODO inline
    bool timeToUpdate();
    bool timeToRender();
    void updateFinished();
    void renderFinished();
    void paused();
    void exit();

    Stepper(const Stepper&);
    Stepper & operator = (const Stepper &);

protected:
    

private:
    Type type = Type::NORMAL;
};

#endif /* STEPPER_H */