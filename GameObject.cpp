#include "GameObject.h"

vector <objectsLoader> allObjects;

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

    identifier = allObjects.size();
    position_x = initial_x;
    position_y = initial_y;

    colisor = has_colision;
    colison_state = false;
    movement = has_movement;
    animate = has_animation;
    motionType = allDirections;

    vectorPlaceHolder.ident = identifier;
    vectorPlaceHolder.name = sprite_name;
    vectorPlaceHolder.pos_x = position_x;
    vectorPlaceHolder.pos_y = position_y;
    vectorPlaceHolder.sprite = objectBody;

    allObjects.push_back(vectorPlaceHolder);
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
        objectBody.setAnimacao(2);
        objectBody.avancarAnimacao();
    }

    if (movement) {
        motionEngine.move(position_x, position_y, speed, objectBody, motionType);
    }

    if (colisor) {
        colisionTester();
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

void GameObject::colisionTester()
{
    int total = allObjects.size();
    colison_state = false;

    for (int iterator = 0; iterator < total; iterator++) {

        if (iterator != identifier) {
            colison_state = uniTestarColisao(
                objectBody, position_x, position_y, 0,
                allObjects[iterator].sprite, allObjects[iterator].pos_x, allObjects[iterator].pos_y, 0
            );

            gDebug.depurar("Colidiu", colison_state);

            if (colison_state == true) {
                colision_identifier = allObjects[iterator].ident;
                gDebug.depurar("Colidiu com ", allObjects[iterator].name);
                gDebug.depurar("Colidiu com ident ", allObjects[iterator].ident);
                break;
            }
        }
    }
}
