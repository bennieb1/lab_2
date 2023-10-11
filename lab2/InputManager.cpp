#include "InputManager.h"
#include <iostream>
#include <SDL.h>


InputManager::InputManager() 
{

	std::cout << "new InputManager" << std::endl;

}

InputManager::~InputManager() 
{

	std::cout << " InputManager destroyed " << std::endl;
	
}

void InputManager::initilize()
{

	std::cout << "INPUTMANAGER INITIALIZED" << std::endl;

}

void InputManager::Load()
{

	std::cout << "Load InputManager" << std::endl;

}

void InputManager::Update() 
{

	std::cout << "INPUTMANAGER UPDATED" << std::endl;
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		
	}


}

void InputManager::Destroy() 
{

	std::cout << "INPUTMANAGER DESTROYED" << std::endl;


}