#pragma once
#include "libUnicornio.h"
#include "GameObject.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

protected:

    GameObject personagem;
    GameObject personagemTeste;
    GameObject personagemTeste2;

};

