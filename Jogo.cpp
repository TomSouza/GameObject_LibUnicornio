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
    personagem.changeAnimation(2);
    personagem.setAnimationSpeed(3);
    personagem.setSpeed(1.5);
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

		uniTerminarFrame();
	}
}