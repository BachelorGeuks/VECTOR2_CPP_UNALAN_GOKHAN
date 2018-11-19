#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include <iostream>
#include "Constantes.h"

#ifndef Game_H_INCLUDED
#define Game_H_INCLUDED

int const WINDOWWIDTH = 640;	//Longueur de la fen�tre
int const WINDOWHEIGHT = 480;	//Largeur de la fen�tre
int const FPS = 30;	//nombre de FPS

class cGame {
	private:	//accessible dans la classe et seulement dans la classe.
		SDL_Window *mpt_window;	//fen�tre
		SDL_Renderer *mpt_renderer;	//rendu
		cPlayer m_player;	//player
		int lastTime2;	//timer pour l'animation
		SDL_Event event;	//event touche
		cVect2D lastPosition;	//R�cup�re la position position du joueur
		int resume;	//boucle de jeu
		int currentTime;	//temps actuel (gettick())
		int lastTime;	//timer pour les FPS
		int cpt;	//compteur pour les animations
		//MovementDirection m_movement;
	protected:	//accessible dans la classe et depuis les parents.
	public:	//accessible de partout.
		cGame();	//constructeur
		~cGame();	//destructeur
		bool OnCreate();	//init des valeurs au lancement du programme
		void OnUpdate();	//boucle de jeu
		void SetWindow(SDL_Window*);	//set la fen�tre
		SDL_Window* GetWindow();	//r�cup�re la fen�tre
		SDL_Renderer* GetRenderer();	//r�cup�re le rendu
		void SetRenderer(SDL_Renderer*);	//set le rendu
		bool InitGame();	//init de la SDL
};

#endif // !Game_H_INCLUDED
