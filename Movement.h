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
    void move(float &pos_x, float &pos_y, float speed);

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

    float speed;
};