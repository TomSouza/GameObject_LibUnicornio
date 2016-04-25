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
    void move(float &pos_x, float &pos_y, float speed);

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

    float speed;
};