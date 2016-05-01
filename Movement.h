#pragma once
#include "libUnicornio.h"

/// <summary>
/// Classe responsável por controlar a movimentação do objeto de jogo
/// </summary>
class Movement
{
public:
    Movement();
    ~Movement();

    /// <summary>
    /// Move o objeto
    /// </summary>
    /// <param name="pos_x"> Posição atual do eixo X do objeto </param>
    /// <param name="pos_y"> Posição atual do eixo Y do objeto </param>
    /// <param name="speed"> Velocidade que será utilizada no incremento da posição </param>
    /// <param name="body"> Sprite do objeto </param>
    /// <param name="motionType"> Tipo do movimento </param>
    void move(float &pos_x, float &pos_y, float speed, Sprite &body, int motionType );

    /// <summary>
    /// Ajusta qual animação será usada pelo movimento. Animações que receberem valor zero
    /// não serão modificadas, já que o valor inicial de todas é zero.
    /// </summary>
    /// <param name="set_stopped"> Numero da animação do objeto parado </param>
    /// <param name="set_up"> Numero da animação para cima </param>
    /// <param name="set_down"> Numero da animação para baixo </param>
    /// <param name="set_left"> Numero da animação para esquerda </param>
    /// <param name="set_right"> Numero da animação para direita </param>
    /// <param name="invert"> Array que indica qual animação sera invertida </param>
    void animationAdjustment(int set_stopped, int set_up, int set_down, int set_left, int set_right, bool *invert);

protected:

    /// <summary>
    /// Teclas padrões que serão utilizadas para movimento
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