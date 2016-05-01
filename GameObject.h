#pragma once
#include "libUnicornio.h"
#include "Movement.h"

/// <summary>
/// Classe respons�vel por controlar fun��es b�sicas de um objeto de jogo
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
    /// Inicializa um objeto de jogo com informa��es b�sicas sobre ele
    /// </summary>
    /// <param name="sprite_name"> Nome do spritesheet j� carregado que ser� usado no objeto </param>
    /// <param name="initial_x"> Posi��o inicial do objeto no eixo X </param>
    /// <param name="initial_y"> Posi��o inicial do objeto no eixo Y </param>
    /// <param name="has_colision"> Determina se o objeto ter� colisor; por padr�o n�o possuir� </param>
    /// <param name="has_movement"> Determina se o objeto ter� movimento; por padr�o n�o possuir� </param>
    /// <param name="has_animation"> Determina se o objeto ter� anima��o; por padr�o n�o possuir� </param>
    void initialize(
            string sprite_name, 
            float initial_x, 
            float initial_y, 
            bool has_colision = false, 
            bool has_movement = false, 
            bool has_animation = false
    );

    /// <summary>
    /// Determina se o objeto ter� ou n�o um colisor
    /// </summary>
    /// <param name="state"> Estado de atividade do colisor </param>
    void setColisor(bool state);

    /// <summary>
    /// Determina se o objeto ter� movimento que por padr�o ser� para todos os lados se estiver ativo
    /// </summary>
    /// <param name="state"> Estado de atividade do movimento </param>
    /// <param name="type"> Tipo de movimeto que o objeto ter� </param>
    void setMovement(bool state , movementType type = allDirections);

    /// <summary>
    /// Determina se o objeto ter� ou n�o uma anima��o
    /// </summary>
    /// <param name="state"> Estado de atividade da anima��o </param>
    void setAnimation(bool state);

    /// <summary>
    /// Desenha o obejto na tela do jogo; tamb�m possui controle sobre 
    /// a verifica��o do movimento e das colis�es
    /// </summary>
    void draw();

    /// <summary>
    /// Muda a anima��o que o objeto est� utilizando
    /// </summary>
    /// <param name="animation_line"> Faixa de anima��o que ser� utilizada </param>
    void changeAnimation(int animation_line);

    /// <summary>
    /// Determina a velocidade de anima��o do objeto
    /// </summary>
    /// <param name="speed"> Velocidade que ser� passsada para a anima��o </param>
    void setAnimationSpeed(float speed);

    /// <summary>
    /// Determina a velocidade de movimento do objeto
    /// </summary>
    /// <param name="speed_to_set"> Velocidade que ser� passsada para o objeto </param>
    void setSpeed(float speed_to_set);

    /// <summary>
    /// Define as anima��es para os movimentos
    /// </summary>
    /// <param name="set_up"> Define n�mero da anima��o para o objeto parado </param>
    /// <param name="set_up"> Define n�mero da anima��o para cima </param>
    /// <param name="set_down"> Define n�mero da anima��o para baixo </param>
    /// <param name="set_left"> Define n�mero da anima��o para esquerda </param>
    /// <param name="set_right"> Define n�mero da anima��o para direita </param>
    void setMovementAnimation(int set_stopped, int set_up, int set_down, int set_left, int set_right);

    /// <summary>
    /// Seta array que define invers�o das anima��es para os movimentos
    /// </summary>
    /// <param name="set_up"> Define invers�o da anima��o para cima </param>
    /// <param name="set_down"> Define invers�o da anima��o para baixo </param>
    /// <param name="set_left"> Define invers�o da anima��o para esquerda </param>
    /// <param name="set_right"> Define invers�o da anima��o para direita </param>
    void choiceAnimationToInvert(bool set_up, bool set_down, bool set_left, bool set_right);

protected:

    bool colisor, movement, animate;
    Movement motionEngine;
    movementType motionType;
    Sprite objectBody;
    float position_x, position_y, speed;
    bool invert[4] = { false, false, false, false };
};