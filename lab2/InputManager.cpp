#include "InputManager.h"
#include <iostream>
#include <SDL.h>


InputManager::InputManager() {

	//construct logic here

}

InputManager::~InputManager() {

	std::cout << " InputManager destroyed " << std::endl;
	
}

void InputManager::initilize() {
	std::cout << "INPUTMANAGER INITIALIZED" << std::endl;
}

void InputManager::Load() {

}

void InputManager::Update() {

	std::cout << "INPUTMANAGER UPDATED" << std::endl;
	// Handle input events here, such as key presses, mouse movements, etc.
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		// Handle specific events if necessary
	}


}

void InputManager::Destroy() {

	std::cout << "INPUTMANAGER DESTROYED" << std::endl;


}