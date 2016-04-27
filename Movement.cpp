#include "Movement.h"

Movement::Movement()
{
}

Movement::~Movement()
{
}

void Movement::move(float &pos_x, float &pos_y, float speed)
{
    gDebug.depurar("pos X Mov", pos_x);
    gDebug.depurar("pos Y Mov", pos_y);
    gDebug.depurar("speed Mov", speed);

    if (gTeclado.segurando[up]) {
        pos_y -= speed;
    }

    if (gTeclado.segurando[down]) {
        pos_y += speed;
    }

    if (gTeclado.segurando[left]) {
        pos_x -= speed;
    }

    if (gTeclado.segurando[right]) {
        pos_x += speed;
    }
}