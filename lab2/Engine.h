#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>

#include "renderSys.h"





class Engine {
private:
	RenderSystem* renderSystem = nullptr;


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

