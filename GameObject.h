#pragma once
#include "libUnicornio.h"
#include "Movement.h"

/// <summary>
/// Classe responsável por controlar funções básicas de um objeto de jogo
/// </summary>
class GameObject
{
public:
    GameObject();
    ~GameObject();

    /// <summary>
    /// Enumerador de tipos de movimento que podem ser livres (allDirections)
    /// ou como um jogo de plataforma (side2side)
    /// </summary>
    enum movementType {
        allDirections, crossArrow, side2side
    };

    /// <summary>
    /// Inicializa um objeto de jogo com informações básicas sobre ele
    /// </summary>
    /// <param name="sprite_name"> Nome do spritesheet já carregado que será usado no objeto </param>
    /// <param name="initial_x"> Posição inicial do objeto no eixo X </param>
    /// <param name="initial_y"> Posição inicial do objeto no eixo Y </param>
    /// <param name="has_colision"> Determina se o objeto terá colisor; por padrão não possuirá </param>
    /// <param name="has_movement"> Determina se o objeto terá movimento; por padrão não possuirá </param>
    /// <param name="has_animation"> Determina se o objeto terá animação; por padrão não possuirá </param>
    void initialize(
            string sprite_name, 
            float initial_x, 
            float initial_y, 
            bool has_colision = false, 
            bool has_movement = false, 
            bool has_animation = false
    );

    /// <summary>
    /// Determina se o objeto terá ou não um colisor
    /// </summary>
    /// <param name="state"> Estado de atividade do colisor </param>
    void setColisor(bool state);

    /// <summary>
    /// Determina se o objeto terá movimento que por padrão será para todos os lados se estiver ativo
    /// </summary>
    /// <param name="state"> Estado de atividade do movimento </param>
    /// <param name="type"> Tipo de movimeto que o objeto terá </param>
    void setMovement(bool state , movementType type = allDirections);

    /// <summary>
    /// Determina se o objeto terá ou não uma animação
    /// </summary>
    /// <param name="state"> Estado de atividade da animação </param>
    void setAnimation(bool state);

    /// <summary>
    /// Desenha o obejto na tela do jogo; também possui controle sobre 
    /// a verificação do movimento e das colisões
    /// </summary>
    void draw();

    /// <summary>
    /// Muda a animação que o objeto está utilizando
    /// </summary>
    /// <param name="animation_line"> Faixa de animação que será utilizada </param>
    void changeAnimation(int animation_line);

    /// <summary>
    /// Determina a velocidade de animação do objeto
    /// </summary>
    /// <param name="speed"> Velocidade que será passsada para a animação </param>
    void setAnimationSpeed(float speed);

    /// <summary>
    /// Determina a velocidade de movimento do objeto
    /// </summary>
    /// <param name="speed_to_set"> Velocidade que será passsada para o objeto </param>
    void setSpeed(float speed_to_set);

    /// <summary>
    /// Define as animações para os movimentos
    /// </summary>
    /// <param name="set_up"> Define número da animação para o objeto parado </param>
    /// <param name="set_up"> Define número da animação para cima </param>
    /// <param name="set_down"> Define número da animação para baixo </param>
    /// <param name="set_left"> Define número da animação para esquerda </param>
    /// <param name="set_right"> Define número da animação para direita </param>
    void setMovementAnimation(int set_stopped, int set_up, int set_down, int set_left, int set_right);

    /// <summary>
    /// Seta array que define inversão das animações para os movimentos
    /// </summary>
    /// <param name="set_up"> Define inversão da animação para cima </param>
    /// <param name="set_down"> Define inversão da animação para baixo </param>
    /// <param name="set_left"> Define inversão da animação para esquerda </param>
    /// <param name="set_right"> Define inversão da animação para direita </param>
    void choiceAnimationToInvert(bool set_up, bool set_down, bool set_left, bool set_right);

protected:

    bool colisor, movement, animate;
    Movement motionEngine;
    movementType motionType;
    Sprite objectBody;
    float position_x, position_y, speed;
    bool invert[4] = { false, false, false, false };
};