#pragma once
#include "libUnicornio.h"
#include "GameObject.h"

class Personagem : public GameObject
{
public:
    Personagem();
    ~Personagem();

    void execute();
    void colisionEvent(int objectIdent);
};
