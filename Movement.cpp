#include "Movement.h"

Movement::Movement()
{
}

Movement::~Movement()
{
}

void Movement::move(float &pos_x, float &pos_y, float speed, Sprite &body, int motionType)
{
    gDebug.depurar("pos X Mov", pos_x);
    gDebug.depurar("pos Y Mov", pos_y);
    gDebug.depurar("speed Mov", speed);
    gDebug.depurar("Tipo", motionType);

    bool advance = false;

    switch (motionType) {
        case 0: // All Directions

            if (gTeclado.segurando[up]) {
                pos_y -= speed;
                body.setAnimacao(animations.up);
                body.setInverterY(inversions[0]);
                advance = true;
            }

            if (gTeclado.segurando[down]) {
                pos_y += speed;
                body.setAnimacao(animations.down);
                body.setInverterY(inversions[1]);
                advance = true;
            }

            if (gTeclado.segurando[left]) {
                pos_x -= speed;
                body.setAnimacao(animations.left);
                body.setInverterX(inversions[2]);
                advance = true;
            }

            if (gTeclado.segurando[right]) {
                pos_x += speed;
                body.setAnimacao(animations.right);
                body.setInverterX(inversions[3]);
                advance = true;
            }

            if (advance) {
                body.avancarAnimacao();
            } else {
                body.setAnimacao(animations.stopped);
                body.recomecarAnimacao();
            }

            break;
        case 1: // Cross Arrow

            if (gTeclado.segurando[up]) {
                pos_y -= speed;
                body.setAnimacao(animations.up);
                body.setInverterY(inversions[0]);
                body.avancarAnimacao();

            } else if (gTeclado.segurando[down]) {
                pos_y += speed;
                body.setAnimacao(animations.down);
                body.setInverterY(inversions[1]);
                body.avancarAnimacao();

            } else if (gTeclado.segurando[left]) {
                pos_x -= speed;
                body.setAnimacao(animations.left);
                body.setInverterX(inversions[2]);
                body.avancarAnimacao();

            } else if (gTeclado.segurando[right]) {
                pos_x += speed;
                body.setAnimacao(animations.right);
                body.setInverterX(inversions[3]);
                body.avancarAnimacao();

            } else {
                body.setAnimacao(animations.stopped);
                body.recomecarAnimacao();
            }

            break;
    }
}

void Movement::animationAdjustment(int set_stopped, int set_up, int set_down, int set_left, int set_right, bool *invert)
{
    if (set_stopped != 0) {
        animations.stopped= set_stopped;
    }

    if (set_up != 0) {
        animations.up = set_up;
    }

    if (set_down != 0) {
        animations.down = set_down;
    }

    if (set_left != 0) {
        animations.left = set_left;
    }

    if (set_right != 0) {
        animations.right = set_right;
    }

    for (int count = 0; count < invert_size; count++) {
        inversions[count] = invert[count];
    }
}