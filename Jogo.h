#pragma once
#include "libUnicornio.h"
#include "Personagem.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

protected:

    Personagem personagem;
    Personagem personagemTeste;
    Personagem personagemTeste2;
    Personagem personagemTeste3;

};

