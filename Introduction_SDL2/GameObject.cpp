#include "GameObject.h"

/*
//BUT:constructeur
//ENTREE
//SORTIE:
*/
cGameObject::cGameObject():mpt_sprite()
{
	mpt_boxCollider = { 0,0,0,0 };
}

/*
//BUT:get le gameobject
//ENTREE
//SORTIE:
*/
cGameObject cGameObject::GetGameObject()
{
	cGameObject tmpGameObject;

	tmpGameObject.SetBoxCollider(mpt_boxCollider);
	tmpGameObject.SetSprites(mpt_sprite);

	return cGameObject();
}

/*
//BUT:Set les sprites
//ENTREE: array de sprite
//SORTIE:
*/
void cGameObject::SetSprites(cSprite sprite[])
{
	for (int i = 0;i < NBRANIMATIONS;i++)
		mpt_sprite[i] = sprite[i];
}

/*
//BUT:set un sprite avec un sprite et un entier
//ENTREE: 1 sprite et 1 entier
//SORTIE:
*/
void cGameObject::SetSprite(cSprite sprite, int position)
{
	mpt_sprite[position] = sprite;
}

/*
//BUT:get les sprites
//ENTREE:
//SORTIE:array de sprite
*/
cSprite* cGameObject::GetSprites()
{
	return mpt_sprite;
}

/*
//BUT:get sprite
//ENTREE:
//SORTIE:1 sprite
*/
cSprite cGameObject::GetSprite(int position)
{
	return mpt_sprite[position];
}

/*
//BUT:set Rect
//ENTREE:1 vecteur 2 entier
//SORTIE:
*/
void cGameObject::SetBoxCollider(cVect2D position, int width, int height)
{
	mpt_boxCollider.x = (int)position.GetVectX();
	mpt_boxCollider.y = (int)position.GetVectY();
	mpt_boxCollider.w = width;
	mpt_boxCollider.h = height;
}

/*
//BUT:set Rect
//ENTREE:1 Rect
//SORTIE:
*/
void cGameObject::SetBoxCollider(SDL_Rect rect)
{
	mpt_boxCollider = rect;
}

/*
//BUT:Get Rect
//ENTREE:
//SORTIE:1 Rect
*/
SDL_Rect* cGameObject::GetBoxCollider()
{
	return &mpt_boxCollider;
}

/*
//BUT:Set position
//ENTREE:1 vecteur
//SORTIE:
*/
void cGameObject::SetPosition(cVect2D position)
{
	mpt_boxCollider.x = (int)position.GetVectX();
	mpt_boxCollider.y = (int)position.GetVectY();
}

/*
//BUT:set position
//ENTREE:2 entier
//SORTIE:
*/
void cGameObject::SetPosition(int x, int y)
{
	mpt_boxCollider.x = x;
	mpt_boxCollider.y = y;
}

/*
//BUT:get position
//ENTREE:
//SORTIE:1 vecteur
*/
cVect2D cGameObject::GetPosition()
{
	return cVect2D{ (float)mpt_boxCollider.x , (float)mpt_boxCollider.y };
}

/*
//BUT:Affiche l'objet
//ENTREE:1 renderer 1 MovementDirection 1 bool 1 entier
//SORTIE:
*/
void cGameObject::Draw(SDL_Renderer *renderer, MovementDirection mov, bool isMoving, int cpt)
{
	if (!isMoving) {
		if (mov != MOVE_LEFT && mov != MOVE_RIGHT) {
			SDL_RenderClear(renderer);
		}
		switch (mov) {
		case IDLE_LEFT:
			SDL_RenderCopyEx(renderer, mpt_sprite[0].GetTexture(), NULL, &mpt_boxCollider, NULL, NULL, SDL_FLIP_HORIZONTAL);
			break;
		case IDLE_RIGHT:
			SDL_RenderCopy(renderer, mpt_sprite[0].GetTexture(), NULL, &mpt_boxCollider);
			break;
		}
	}
	else {
		if (mov != IDLE_LEFT && mov != IDLE_RIGHT) {
			SDL_RenderClear(renderer);
		}
		switch (mov) {
		case MOVE_LEFT:
			SDL_RenderCopyEx(renderer, mpt_sprite[cpt].GetTexture(), NULL, &mpt_boxCollider, NULL, NULL, SDL_FLIP_HORIZONTAL);
			break;
		case MOVE_RIGHT:
			SDL_RenderCopy(renderer, mpt_sprite[cpt].GetTexture(), NULL, &mpt_boxCollider);
			break;
		}
	}
}

/*
//BUT:Init les animations
//ENTREE:1 renderer 2 string
//SORTIE: 1 bool
*/
bool cGameObject::InitAnimation(SDL_Renderer *renderer, std::string imageName, std::string format) {
	cSprite sprite[NBRANIMATIONS];


	for (int i = 0; i < NBRANIMATIONS; i++) {
		bool test = false;
		std::string name = imageName + std::to_string(i) + format;

		sprite[i].LoadSprite(name, renderer);
		if (sprite[i].GetTexture() == nullptr) {
			printf("Sprite Error: %s\n", IMG_GetError());
			return false;
		}
		else {
			std::cout << "Sprite " + std::to_string(i) + " loaded." << std::endl;
		}
	}

	SetSprites(sprite);
	return true;
}

/*
//BUT:get taille animations
//ENTREE:
//SORTIE: 1 entier
*/
int cGameObject::GetLength() {
	return NBRANIMATIONS;
}