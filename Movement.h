#pragma once
#include "libUnicornio.h"

class Movement
{
public:
    Movement();
    ~Movement();

    void move(float &pos_x, float &posy, float speed);

protected:
    enum defautl_comands {
        up = TECLA_W,
        down = TECLA_S,
        left = TECLA_A,
        right = TECLA_D
    };

    float speed;
};