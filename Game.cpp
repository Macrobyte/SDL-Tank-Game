#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;

bool Game::InitializeSDL(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	printf("Initializing SDL...\n");

	//Attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		int flags = 0;
		if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

		//Attempt to initialize SDL window
		if (!(m_sdlWindow = SDL_CreateWindow(title, xpos, ypos, m_ScreenWidth, m_ScreenHeight, flags)))
			std::cout << "Failed to create window. SDL error: " << SDL_GetError() << std::endl; //If window fails to initialize
		else
			//Attempt to initialize SDL renderer
			if (!(m_sdlRenderer = SDL_CreateRenderer(m_sdlWindow, -1, SDL_RENDERER_ACCELERATED)))
				std::cout << "Failed to create renderer. SDL error: " << SDL_GetError() << std::endl; // If renderer fails to initialize
	}
	else
	{
		std::cout << "Failed to initialize SDL. SDL error: " << SDL_GetError() << std::endl;
	}

	printf("SDL initialized.\n");
	
	m_IsRunning = true; //If everything initialized fine, start the main loop

	InputHandler::Initialize();
	
	if (!TextureManager::Instance()->LoadTexture("Assets/RedTankBody.png", "TankBody", m_sdlRenderer))
	{
		printf("Failed to load texture.\n");
		return false;
	}

	if (!TextureManager::Instance()->LoadTexture("Assets/RedTankTurret.png", "TankTurret", m_sdlRenderer))
	{
		printf("Failed to load texture.\n");
		return false;
	}

	m_GameObjects.push_back(new PlayerTank(new TextureLoader(60, 60, 86, 66, "TankBody"), new TextureLoader(0, 0, 38, 91, "TankTurret")));
	
	return true;
	
}

void Game::Render()
{
	//Clear the renderer
	SDL_RenderClear(m_sdlRenderer);

	//Loop through our objects and draw them
	for (std::vector<GameObject*>::size_type i = 0; i != m_GameObjects.size(); i++)
	{
		m_GameObjects[i]->Draw();
	}

	
	//Draw to the screen 
	
	SDL_RenderPresent(m_sdlRenderer);
}


void Game::Update()
{
	m_CurrentFrame = int(((SDL_GetTicks() / 100) % 6));

	for (std::vector<GameObject*>::size_type i = 0; i != m_GameObjects.size(); i++)
	{
		m_GameObjects[i]->Update();
	}


	//Update the input handler
	InputHandler::Update();
	
}

void Game::HandleEvents()
{
	SDL_Event event;

	//Handle events on queue
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_MOUSEMOTION:		
			InputHandler::OnMouseMove(event);
			//printf("Mouse X: %d Y: %d \n", (int)InputHandler::GetMousePosition()->GetX(), (int)InputHandler::GetMousePosition()->GetY());
			break;			
		case SDL_MOUSEBUTTONDOWN:
			InputHandler::GetMouseButtonDown(event);
			//printf("Mouse button %d\n", event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			InputHandler::GetMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			InputHandler::GetKeyDown(event.key.keysym.scancode);
			break;	
		case SDL_KEYUP:
			InputHandler::GetKeyUp(event.key.keysym.scancode);
			break;
		case SDL_QUIT:
			m_IsRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::Clean()
{
	printf("Cleaning up...\n");
	SDL_DestroyWindow(m_sdlWindow);
	SDL_DestroyRenderer(m_sdlRenderer);
	InputHandler::Clean();
	SDL_Quit();
}

void Game::Quit()
{
	SDL_Quit();
}


