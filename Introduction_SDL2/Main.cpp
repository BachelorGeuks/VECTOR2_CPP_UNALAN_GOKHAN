/*
//BUT: Animer un spritesheet et le d�placer
//ENTREE:input de l'utilisateur
//SORTIE:
*/
#include "Game.h"

int main(int argc, char * argv[])
{
	cGame game;

	if(game.OnCreate())
		game.OnUpdate();

	return 0;
}