#pragma once
#include "libUnicornio.h"
#include "Movement.h"

class GameObject
{
public:
    GameObject();
    ~GameObject();

    enum movementType {
        allDirections, side2side
    };

    void initialize(string sprite_name, float initial_x, float initial_y, bool has_colision, bool has_movement, bool has_animation);

    void setColisor(bool state);
    void setMovement(bool state , movementType type = allDirections);
    void setAnimation(bool state);

    void draw();
    void changeAnimation(int animation_line);
    void setAnimationSpeed(float speed);

    void setSpeed(float speed_to_set);

protected:

    bool colisor, movement, animate;
    Movement motionEngine;
    movementType motionType;
    Sprite objectBody;
    float position_x, position_y, speed;
};