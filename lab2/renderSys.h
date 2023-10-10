#pragma once
 #ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H


#include <string>

#include <SDL.h>

#include "json.hpp"


class RenderSystem {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::string name = " ";
	int width;
	int height = 0;
	bool fullscreen = false;


public:
	RenderSystem();
	~RenderSystem();

	void Initialize(const std::string& settingsFilePath);
	void Destroy();
	void Update();
	void Load();
	

	// Getter and Setter methods (if needed)
	std::string GetName() const;
	void SetName(const std::string& name);

	int GetWidth() const;
	void SetWidth(int width);

	int GetHeight() const;
	void SetHeight(int height);

	bool IsFullscreen() const;
	void SetFullscreen(bool fullscreen);

};

#endif // RENDERSYSTEM_H

