#include "Game.h"

/*
//BUT:Init au lancement
//ENTREE:variables membres
//SORTIE:1 bool
*/
bool cGame::OnCreate()
{
	//init de la SDL
	if (!InitGame())
		return false;

	//init du player
	cVect2D position = { WINDOWWIDTH / 2,WINDOWHEIGHT / 2 };
	if (!m_player.OnCreate(mpt_renderer, position))
		return false;

	return true;
}

/*
//BUT:boucle de jeu
//ENTREE:variables membres
//SORTIE:
*/
void cGame::OnUpdate() {
	cVect2D lastPosition = m_player.GetGameObject()->GetPosition();
	//boucle de jeu
	while (!resume)
	{
		SDL_PollEvent(&event);
		m_player.GetInput()->Input(event,&resume);

		//30fps affichage
		currentTime = SDL_GetTicks();
		if (currentTime - lastTime > FPS) {
			//boucle du player
			m_player.OnUpdate(mpt_renderer,&lastTime2,&cpt,lastPosition);
			
			lastTime = currentTime;
		}
		else    //economisé le proc sinon tourne a 100%
			SDL_Delay(FPS - (currentTime - lastTime));
		SDL_RenderPresent(mpt_renderer);
	}
}

/*
//BUT:Constructeur
//ENTREE:variables membres
//SORTIE:
*/
cGame::cGame()
{
	mpt_window = nullptr;
	mpt_renderer = nullptr;
	lastTime2 = 0;
	resume = 0;
	currentTime = 0;
	lastTime = 0;
	cpt = 0;
}

/*
//BUT:Destructeur
//ENTREE:
//SORTIE:
*/
cGame::~cGame()
{
	SDL_DestroyRenderer(mpt_renderer);
	SDL_DestroyWindow(mpt_window);
	IMG_Quit();
	SDL_Quit();
}

/*
//BUT:Set window
//ENTREE:SDL_Window
//SORTIE:
*/
void cGame::SetWindow(SDL_Window * window)
{
	mpt_window = window;
}

/*
//BUT:get Widow
//ENTREE:
//SORTIE:SDL_Window
*/
SDL_Window * cGame::GetWindow()
{
	return mpt_window;
}

/*
//BUT:Get Renderer
//ENTREE:
//SORTIE:SDL_Renderer
*/
SDL_Renderer * cGame::GetRenderer()
{
	return mpt_renderer;
}

/*
//BUT:Set Renderer
//ENTREE:SDL_Renderer
//SORTIE:
*/
void cGame::SetRenderer(SDL_Renderer *renderer)
{
	mpt_renderer = renderer;
}

/*
//BUT:Init de la SDL
//ENTREE:
//SORTIE:
*/
bool cGame::InitGame()
{
	int flags;
	int initted;

	//Init de la SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL : Failed to init : %s\n", SDL_GetError());
		return false;
	}
	printf("SDL : OK\n");

	//Init SDL_Image
	flags = IMG_INIT_JPG | IMG_INIT_PNG;
	initted = IMG_Init(flags);
	if ((initted&flags) != flags) {
		printf("SDL_Image: Failed to init required jpg and png support!\n");
		printf("SDL_Image: %s\n", IMG_GetError());
		return false;
	}
	printf("SDL_Image : OK\n");

	//Création et init de la fenêtre
	mpt_window = SDL_CreateWindow("SDL2 Display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOWWIDTH, WINDOWHEIGHT, 0);
	if (mpt_window == nullptr) {
		printf("SDL_Window : Could not create window: %s\n", SDL_GetError());
		return false;
	}
	printf("SDL_Window : OK\n");

	//Création et init du rendu
	mpt_renderer = SDL_CreateRenderer(mpt_window, -1, SDL_RENDERER_ACCELERATED);
	if (mpt_renderer == nullptr) {
		printf("SDL_Renderer : Could not create renderer: %s\n", SDL_GetError());
		return false;
	}
	printf("SDL_Renderer : OK\n");

	return true;
}
