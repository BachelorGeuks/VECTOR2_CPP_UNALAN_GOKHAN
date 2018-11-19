#pragma once
#include <SDL.h>
#include "Constantes.h"

#ifndef Input_H_INCLUDED
#define Input_H_INCLUDED

//Liste des touches
typedef struct Keybinding {
	SDL_Keycode Left;
	SDL_Keycode Right;
}Keybinding;

class cInput {
	private:
		Keybinding m_key;	//Liste des touches
		MovementDirection m_movement;	//direction
	protected:
	public:
		cInput();//constructeur
		void Input(SDL_Event, int*);//event des inputs
		void SetInput(InputKey, SDL_Keycode);//set input
		SDL_Keycode* GetInput(InputKey);//get input
		MovementDirection GetMovementDirection();//get direction
};

#endif // !Input_H_INCLUDED
