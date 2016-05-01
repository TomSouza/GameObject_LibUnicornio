#pragma once
#include "libUnicornio.h"

/// <summary>
/// Classe respons�vel por controlar a movimenta��o do objeto de jogo
/// </summary>
class Movement
{
public:
    Movement();
    ~Movement();

    /// <summary>
    /// Move o objeto
    /// </summary>
    /// <param name="pos_x"> Posi��o atual do eixo X do objeto </param>
    /// <param name="pos_y"> Posi��o atual do eixo Y do objeto </param>
    /// <param name="speed"> Velocidade que ser� utilizada no incremento da posi��o </param>
    /// <param name="body"> Sprite do objeto </param>
    /// <param name="motionType"> Tipo do movimento </param>
    void move(float &pos_x, float &pos_y, float speed, Sprite &body, int motionType );

    /// <summary>
    /// Ajusta qual anima��o ser� usada pelo movimento. Anima��es que receberem valor zero
    /// n�o ser�o modificadas, j� que o valor inicial de todas � zero.
    /// </summary>
    /// <param name="set_stopped"> Numero da anima��o do objeto parado </param>
    /// <param name="set_up"> Numero da anima��o para cima </param>
    /// <param name="set_down"> Numero da anima��o para baixo </param>
    /// <param name="set_left"> Numero da anima��o para esquerda </param>
    /// <param name="set_right"> Numero da anima��o para direita </param>
    /// <param name="invert"> Array que indica qual anima��o sera invertida </param>
    void animationAdjustment(int set_stopped, int set_up, int set_down, int set_left, int set_right, bool *invert);

protected:

    /// <summary>
    /// Teclas padr�es que ser�o utilizadas para movimento
    /// </summary>
    enum default_commands {
        up = TECLA_W,
        down = TECLA_S,
        left = TECLA_A,
        right = TECLA_D
    };

    struct animateMove {
        int stopped = 0;
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;
    };

    animateMove animations;
    float speed;

    const int invert_size = 4;
    bool inversions[4] = { };
};