#pragma once
 #ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H


#include <string>





class RenderSystem {
private:
	std::string name = " ";
	int width = 0;
	int height = 0;
	bool fullscreen = true;


public:
	RenderSystem();
	~RenderSystem();

	void Initialize();
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

