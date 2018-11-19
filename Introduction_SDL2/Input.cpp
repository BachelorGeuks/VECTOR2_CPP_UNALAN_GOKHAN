#include "Input.h"

/*
//BUT:constructeur
//ENTREE
//SORTIE:
*/
cInput::cInput()
{
	m_key.Left = NULL;
	m_key.Right = NULL;
}

/*
//BUT:event des inputs
//ENTREE
//SORTIE:
*/
void cInput::Input(SDL_Event event, int *resume)
{
	switch (event.type) {
	case SDL_QUIT:
		*resume = 1;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			m_movement = MOVE_LEFT;
			break;
		case SDLK_RIGHT:
			m_movement = MOVE_RIGHT;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			m_movement = IDLE_LEFT;
			break;
		case SDLK_RIGHT:
			m_movement = IDLE_RIGHT;
			break;
		default:
			break;
		}
		break;
	}
}

/*
//BUT:set input en paramètre la touche voulu et par quel touche jouer
//ENTREE1 inputKey 1 SDL_Keycode
//SORTIE:
*/
void cInput::SetInput(InputKey input, SDL_Keycode key)
{
	switch (input) {
	case K_LEFT:
		m_key.Left = key;
		break;

	case K_RIGHT:
		m_key.Right = key;
		break;
	}
}

/*
//BUT:get input
//ENTREE: l'input voulu
//SORTIE:SDL_Keycode
*/
SDL_Keycode* cInput::GetInput(InputKey input)
{
	switch (input) {
		case K_LEFT:
			return &m_key.Left;
			break;

		case K_RIGHT:
			return &m_key.Right;
			break;
		default:
			break;
	}
}

/*
//BUT:get direction
//ENTREE
//SORTIE:MovementDirection
*/
MovementDirection cInput::GetMovementDirection()
{
	return m_movement;
}
