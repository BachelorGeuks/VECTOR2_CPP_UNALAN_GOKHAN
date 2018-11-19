#pragma once

#include "Input.h"
#include "GameObject.h"

#ifndef Player_H_INCLUDED
#define Player_H_INCLUDED

std::string const NAMESPRITE = "Hat_man";	//Nom des sprite
std::string const EXTENTIONSPRITE = ".png";	//format des sprites
int const TIMER = 60;	//timer de l'animation en ms

class cPlayer {
	private:
		cGameObject m_gameObject;	//l'objet membre
		cInput m_input;	//input membre
	protected:
	public:
		cPlayer();//constructeur
		void SetGameObject(cGameObject);//set objet
		cGameObject *GetGameObject();//get objet
		cInput* GetInput();//get input
		void SetInput(cInput);//set input
		void OnUpdate(SDL_Renderer*, int*, int*, cVect2D);//boucle du player
		bool OnCreate(SDL_Renderer*, cVect2D);//creation du player
};

#endif // !Player_H_INCLUDED
