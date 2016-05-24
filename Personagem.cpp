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

    if (colison_state == true) {
        colisionEvent(colision_identifier);
    } else {
        objectBody.setCorAzul(255);
        objectBody.setCorVerde(255);
        objectBody.setCorVermelho(255);
    }
}

void Personagem::colisionEvent(int objectIdent)
{
    string otherName = allObjects[objectIdent].name;

    if (otherName == "personagem") {
        if (allObjects[objectIdent].ident == 1) {

            objectBody.setCorAzul(100)
                ;
            objectBody.setCorVerde(200);
            objectBody.setCorVermelho(100);
        } else if (allObjects[objectIdent].ident == 2) {
            objectBody.setCorAzul(200);
            objectBody.setCorVerde(100);
            objectBody.setCorVermelho(100);
        }
        
    }
}