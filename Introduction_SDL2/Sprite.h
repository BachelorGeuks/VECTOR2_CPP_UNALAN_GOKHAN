#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#ifndef Sprite_H_INCLUDED
#define Sprite_H_INCLUDED

class cSprite {
	private:
		SDL_Texture *mpt_texture;	//texture de l'image
	protected:
	public:
		cSprite();	//constructeur
		~cSprite();	//destructeur
		bool LoadSprite(std::string, SDL_Renderer *);	//Chargement de l'image
		SDL_Texture* GetTexture();	//get texture
};

#endif // !Sprite_H_INCLUDED


