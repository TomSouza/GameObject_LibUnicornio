#include "GameObject.h"

GameObject::GameObject()
{
    colisor = movement = animate = true;
}

GameObject::~GameObject()
{
}

/**
 * Inicializador do objeto de jogo
 * Este metodo define informações basicas do 
 * objeto , como o seu spritesheet, sua posição 
 * na tela e se posui colisor, movimento ou animação.
 *
 * @param string sprite_name Nome do spritesheet que já foi previamente carregado
 * @param initial_x
 */
void GameObject::initialize(string sprite_name, float initial_x, float initial_y, bool has_colision, bool has_movement, bool has_animation)
{
    objectBody.setSpriteSheet(sprite_name);

    position_x = initial_x;
    position_y = initial_y;

    colisor = has_colision;
    movement = has_movement;
    animate = has_animation;
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
        motionEngine.move(position_x, position_y, speed);
    }

    gDebug.depurar("pos X", position_x);
    gDebug.depurar("pos Y", position_y);

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