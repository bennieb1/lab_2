#include "Engine.h"
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "SDL.h"


Engine::Engine() : running(false) {
	renderSystem = new RenderSystem();
	inputManager = new InputManager();
	assetManager = new AssetManager();
	sceneManager = new SceneManager();

};

Engine::~Engine() {
	
	std::cout << "ENGINE Destroyed" << std::endl;

};

void Engine::Initialize() {
	LoadSettings("GameSettings.JSON");
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	
		SDL_Log("UNABLE TO INIT SDL",SDL_GetError);

		return;
	}



	renderSystem->Initialize("GameSettings.JSON");
	inputManager->initilize();
	assetManager->initilize();
	sceneManager->Initilize();
	sceneManager->Load("GameLevelExample.JSON");

	running = true;

};

void Engine::Destroy() {

	sceneManager->Destroy();
	assetManager->Destroy();
	inputManager->Destroy();
	renderSystem->Destroy();

	delete sceneManager;
	delete assetManager;
	delete inputManager;
	delete renderSystem;

	SDL_Quit();
}

void Engine::GameLoop() {
	SDL_Event event;

	
	
		while (SDL_PollEvent(&event)) {
		
			if (event.type == SDL_QUIT) {
			
				

			}

			inputManager->Update();
		}

		sceneManager->Update();
		assetManager->Update();
		renderSystem->Update();



		renderSystem->Load();

	
}

class RectInt
{
public:
	int width = 0;
	int height = 0;
	std::string name;

public:
	void Load(json::JSON& _json);

	void Display();
};

void RectInt::Load(json::JSON& _json)
{
	if (_json.hasKey("width")) width = _json["width"].ToInt();
	if (_json.hasKey("height")) height = _json["height"].ToInt();
	


}

void RectInt::Display()
{
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	
}
class GameSettings
{
	std::string name;
	RectInt size;
	std::string defaultFile;

public:
	void Load(json::JSON& _json)
	{
		if (_json["Engine"].hasKey("DefaultFile"))
		{
			defaultFile = _json["Engine"]["DefaultFile"].ToString();
			
		}
		if (_json["RenderSystem"].hasKey("Name"))
		{
			json::JSON& windowSize = _json["RenderSystem"];
			size.Load(windowSize);
			name = _json["RenderSystem"]["Name"] .ToString();
			if (_json["RenderSystem"].hasKey("Name"))
			{

				


			}
			else
			{

				std::cerr << "Error: Game Settings must have a name!" << std::endl;
			}


		}
	}

	void Display()
	{
		std::cout << "Name: " << name.c_str() << std::endl;
		size.Display();
		std::cout << "Default File: " << defaultFile.c_str() << std::endl;
	}
};

void Engine::Load() {
	// Load assets, scenes, or other required resources


	assetManager->Load();


}

void Engine::LoadSettings(const std::string& filepath) {
	std::ifstream inputStream(filepath);
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	GameSettings settings;
	settings.Load(document);

	settings.Display();

}
