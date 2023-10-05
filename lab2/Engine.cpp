#include "Engine.h"
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "renderSys.h"

Engine::Engine() {
	renderSystem = new RenderSystem();

};

Engine::~Engine() {
	Destroy();
};

void Engine::Initialize() {
	LoadSettings("GameSettings.JSON");
	std::cout << "engine initilized" << std::endl;
	renderSystem->Initialize();




};

void Engine::Destroy() {

	renderSystem->Destroy();


	delete renderSystem;
}

void Engine::GameLoop() {
	bool isRunning = true;
	while (isRunning) {
		renderSystem->Update();
		// Check some other conditions
		if (!isRunning)
		{
			isRunning = false;
		}
	}
}

class RectInt
{
public:
	int width = 0;
	int height = 0;
	int x = 0;
	int y = 0;
	std::string name;

public:
	void Load(json::JSON& _json);

	void Display();
};

void RectInt::Load(json::JSON& _json)
{
	if (_json.hasKey("width")) width = _json["width"].ToInt();
	if (_json.hasKey("height")) height = _json["height"].ToInt();
	if (_json.hasKey("x")) width = _json["x"].ToInt();
	if (_json.hasKey("y")) width = _json["y"].ToInt();


}

void RectInt::Display()
{
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
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
			std::cout << defaultFile << std::endl;
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
}

void Engine::LoadSettings(const std::string& filepath) {
	std::ifstream inputStream(filepath);
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	GameSettings settings;
	settings.Load(document);

	settings.Display();

}
