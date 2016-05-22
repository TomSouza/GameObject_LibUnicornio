#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
    uniInicializar(800, 600, false, "GameObject");
    gJanela.setIcone("./assets/images/game_icon.png");

    gRecursos.carregarSpriteSheet(
        "personagem",
        "./assets/spritesheets/esquilo.png",
        3, 4, QUALIDADE_ESCALA_MEDIA
    );

    personagem.initialize("personagem", 400, 400, true, true, true);
    personagem.setMovementAnimation(1, 0, 1, 2, 2);
    personagem.choiceAnimationToInvert(false, false, true, false);
    personagem.setAnimationSpeed(5);
    personagem.setSpeed(1.5);
    personagem.setMovement(true, personagem.crossArrow);

    personagemTeste.initialize("personagem", 600, 400, false, false, true);
    personagemTeste.setSpeed(0);
    personagemTeste2.initialize("personagem", 200, 400, false, false, true);
    personagemTeste2.setSpeed(0);
}

void Jogo::finalizar()
{
    gRecursos.descarregarTudo();
    uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

        personagem.draw();
        personagemTeste.draw();
        personagemTeste2.draw();

		uniTerminarFrame();
	}
}