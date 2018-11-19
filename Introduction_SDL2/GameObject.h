#pragma once
#include <SDL_image.h>
#include "Vect2D.h"
#include "Sprite.h"
#include "Constantes.h"

#ifndef GameObject_H_INCLUDED
#define GameObject_H_INCLUDED

const int NBRANIMATIONS = 4;	//Nombre d'animation
const int SPRITESIZE = 50;	//Taille du sprite

class cGameObject {
	private:
		cSprite mpt_sprite[NBRANIMATIONS];	//les sprites
		SDL_Rect mpt_boxCollider;	//le Rect de l'objet
	protected:
	public:
		cGameObject();//Constructeur
		cGameObject GetGameObject();//get l'objet
		void SetSprite(cSprite,int);	//set le sprite
		void SetSprites(cSprite[]);	//set les sprites
		cSprite* GetSprites();	//get les sprites
		cSprite GetSprite(int);	//get un sprite
		void SetBoxCollider(cVect2D, int, int);	//set le Rect avec un vecteur et 2 entier
		void SetBoxCollider(SDL_Rect);		//set le Rect avec un autre Rect
		SDL_Rect* GetBoxCollider();	//Get le rect
		void SetPosition(cVect2D);	//set la position avec un vecteur
		void SetPosition(int,int);	//set la position avec deux entier
		cVect2D GetPosition();	//get la position
		void Draw(SDL_Renderer*,MovementDirection, bool, int cpt = 0);	//Affiche à l'écran l'objet
		bool InitAnimation(SDL_Renderer *, std::string,std::string);	//init des animations
		int GetLength();	//retourne la taille des animations
};

#endif // !GameObject_H_INCLUDED
