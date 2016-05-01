#include "GameObject.h"

GameObject::GameObject()
{
    colisor = movement = animate = true;
}

GameObject::~GameObject()
{
}

void GameObject::initialize(string sprite_name, float initial_x, float initial_y, bool has_colision, bool has_movement, bool has_animation)
{
    objectBody.setSpriteSheet(sprite_name);

    position_x = initial_x;
    position_y = initial_y;

    colisor = has_colision;
    movement = has_movement;
    animate = has_animation;

    motionType = allDirections;
}

void GameObject::setColisor(bool state)
{
    colisor = state;
}

void GameObject::setMovement(bool state, movementType type)
{
    movement = state;
    motionType = type;
}

void GameObject::setAnimation(bool state)
{
    animate = state;
}

void GameObject::draw()
{
    if (!movement && animate) {
        objectBody.avancarAnimacao();
    }

    if (movement) {
        motionEngine.move(position_x, position_y, speed, objectBody, motionType);
    }

    objectBody.desenhar(position_x, position_y);
}

void GameObject::changeAnimation(int animation_line)
{
    objectBody.setAnimacao(animation_line);
}

void GameObject::setAnimationSpeed(float speed)
{
    objectBody.setVelocidadeAnimacao(speed);
}

void GameObject::setSpeed(float speed_to_set)
{
    speed = speed_to_set;
}

void GameObject::choiceAnimationToInvert(bool set_up, bool set_down, bool set_left, bool set_right)
{
    invert[0] = set_up;
    invert[1] = set_down;
    invert[2] = set_left;
    invert[3] = set_right;

    motionEngine.animationAdjustment(0, 0, 0, 0, 0, invert);
}

void GameObject::setMovementAnimation(int set_stopped, int set_up, int set_down, int set_left, int set_right)
{
    motionEngine.animationAdjustment(set_stopped, set_up, set_down, set_left, set_right, invert);
}