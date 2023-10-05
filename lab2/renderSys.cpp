#include "renderSys.h"

#include <iostream>


RenderSystem::RenderSystem()  {
	// Constructor logic
}

RenderSystem::~RenderSystem()
{
	std::cout << "Render system destroyed " << std::endl;
}

void RenderSystem::Initialize() {
	// Initialize SDL

}

void RenderSystem::Destroy()
{
	std::cout << "rendersys was destroyed" << std::endl;
}


void RenderSystem::Update() {

}

	// Render logic
