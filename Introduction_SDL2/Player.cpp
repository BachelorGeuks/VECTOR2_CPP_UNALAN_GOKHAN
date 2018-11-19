#include "Player.h"

/*
//BUT:constructeur
//ENTREE:
//SORTIE:
*/
cPlayer::cPlayer():m_gameObject(),m_input()
{
}

/*
//BUT:set objet
//ENTREE:1 objet
//SORTIE:
*/
void cPlayer::SetGameObject(cGameObject gm)
{
	m_gameObject = gm;
}

/*
//BUT:get objet
//ENTREE:
//SORTIE:1 objet
*/
cGameObject* cPlayer::GetGameObject()
{
	return &m_gameObject;
}

/*
//BUT:get input
//ENTREE:
//SORTIE:1 input
*/
cInput* cPlayer::GetInput()
{
	return &m_input;
}

/*
//BUT:set input
//ENTREE:1 input
//SORTIE:
*/
void cPlayer::SetInput(cInput input)
{
	m_input = input;
}

/*
//BUT:boucle du player
//ENTREE:1 renderer 2 entier 1 vecteur
//SORTIE:
*/
void cPlayer::OnUpdate(SDL_Renderer * renderer, int* lastTime,int* cpt, cVect2D lastPosition)
{
	int currentTime = SDL_GetTicks();
	
	
	//si le player a bouger
	if (!lastPosition.isSame(m_gameObject.GetPosition())) {
		if (currentTime - *lastTime > TIMER) {
			m_gameObject.Draw(renderer, m_input.GetMovementDirection(), true, *cpt);
			*cpt= *cpt +1;

			if (*cpt == GetGameObject()->GetLength())
				*cpt = 0;
			*lastTime = currentTime;
			lastPosition = m_gameObject.GetPosition();
		}
	}
	else {
		m_gameObject.Draw(renderer, m_input.GetMovementDirection(),false);
		cpt = 0;
	}

	float x = m_gameObject.GetPosition().GetVectX();

	switch (m_input.GetMovementDirection()) {
		case MOVE_LEFT:
			m_gameObject.GetBoxCollider()->x -= 3;
			break;
		case MOVE_RIGHT:
			m_gameObject.GetBoxCollider()->x += 3;
			break;
		default:
			break;
	}
}

/*
//BUT:lancement du player
//ENTREE:1 renderer 1 vecteur
//SORTIE:1 bool
*/
bool cPlayer::OnCreate(SDL_Renderer* renderer, cVect2D position)
{
	//Init rect sprite
	GetInput()->SetInput(K_LEFT, SDLK_LEFT);
	GetInput()->SetInput(K_RIGHT, SDLK_RIGHT);
	GetGameObject()->SetPosition(position);
	GetGameObject()->SetBoxCollider(position, SPRITESIZE, SPRITESIZE);

	if (!GetGameObject()->InitAnimation(renderer, NAMESPRITE, EXTENTIONSPRITE)) {
		printf("Animation: Error\n");
		return false;
	}
	printf("Animation : OK\n");

	return true;
}


