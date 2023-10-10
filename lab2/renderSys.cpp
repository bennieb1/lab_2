#include "renderSys.h"
#include <fstream>
#include <iostream>


RenderSystem::RenderSystem() : window(nullptr) , renderer(nullptr)  {
	std::cout << "RENDERSYSTEM CREATED" << std::endl;
}

RenderSystem::~RenderSystem()
{
    std::cout << "RENDERSYSTEM destroyed " << std::endl;
}



void RenderSystem::Initialize(const std::string& settingsFilePath) {
    std::cout << "RENDERSYSTEM INITIALIZED" << std::endl;

    // Read the JSON data from the file
    std::ifstream inputStream(settingsFilePath);
    if (!inputStream.is_open()) {
        std::cerr << "Failed to open settings file: " << settingsFilePath << std::endl;
        return;
    }
    std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
    json::JSON settings = json::JSON::Load(str);

    // Extract the necessary information from the JSON data
    if (settings["RenderSystem"].hasKey("width")) width = settings["RenderSystem"]["width"].ToInt();
    if (settings["RenderSystem"].hasKey("height")) height = settings["RenderSystem"]["height"].ToInt();
    if(settings["RenderSystem"].hasKey("fullscreen")) fullscreen = settings["RenderSystem"]["fullscreen"].ToBool();

    // Initialize the SDL window and renderer using the extracted information
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


}

void RenderSystem::Destroy()
{

	std::cout << "RENDERSYSTEM DESTROYED" << std::endl;

	if (renderer) {

		SDL_DestroyRenderer(renderer);
	}


    SDL_DestroyWindow(window);

    SDL_Quit();

}

void RenderSystem::Update() {

    std::cout << "RENDERSYSTEM UPDATED" << std::endl;
    SDL_PollEvent(NULL);

}

void RenderSystem::Load() {

	
	

}

	// Render logic
