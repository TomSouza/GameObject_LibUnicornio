#include "Personagem.h"

//vector <objectsLoader> allObjects;

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

void Personagem::execute()
{
    draw();

    if (colison_state == false) {
        objectBody.setCorAzul(255);
        objectBody.setCorVerde(255);
        objectBody.setCorVermelho(255);
    }
}

void Personagem::colisionEvent(objectsLoader objectIdent)
{
    string otherActor = objectIdent.name;

    if (otherActor == "teste1") {
        objectBody.setCorAzul(100);
        objectBody.setCorVerde(200);
        objectBody.setCorVermelho(100);
    } else if (otherActor == "teste2") {
        objectBody.setCorAzul(200);
        objectBody.setCorVerde(100);
        objectBody.setCorVermelho(100);
    }
}