#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "renderSys.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "json.hpp"
#include "SceneManager.h"





class Engine {
private:
	RenderSystem* renderSystem;
	InputManager* inputManager;
	AssetManager* assetManager;
	SceneManager* sceneManager;
	
	bool running;
	json::JSON settings;


public:
	Engine();
	~Engine();

	void Initialize();
	void Destroy();
	void GameLoop();
	void Load();

	void LoadSettings(const std::string& filepath);
};

#endif // ENGINE_H

