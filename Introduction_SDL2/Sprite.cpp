#include "Sprite.h"

/*
//BUT:constructeur
//ENTREE
//SORTIE:
*/
cSprite::cSprite()
{
	mpt_texture = 0;
}

/*
//BUT:destructeur
//ENTREE
//SORTIE:
*/
cSprite::~cSprite()
{
	if(!mpt_texture)
		SDL_DestroyTexture(mpt_texture);
}

/*
//BUT:Chargement de l'image
//ENTREE1 string, 1 renderer
//SORTIE:1 bool
*/
bool cSprite::LoadSprite(std::string path, SDL_Renderer *renderer)
{
	SDL_Surface *tmpSurface = nullptr;
	tmpSurface = IMG_Load(path.c_str());
	
	if (tmpSurface==nullptr) {
		printf("IMG_Load: %s\n", IMG_GetError());
		SDL_FreeSurface(tmpSurface);
		return false;
	}

	mpt_texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	if (mpt_texture == nullptr) {
		SDL_FreeSurface(tmpSurface);
		printf("IMG_Load: %s\n", IMG_GetError());
		return false;
	}
	return true;
}

/*
//BUT:get texture
//ENTREE
//SORTIE:SDL_Texture
*/
SDL_Texture* cSprite::GetTexture()
{
	return mpt_texture;
}
