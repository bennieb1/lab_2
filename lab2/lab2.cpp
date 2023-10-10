
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Engine.h"
#include "renderSys.h"


int main(int argc, char* args[])
{

	
	Engine* engine = new Engine();
	

	engine->Initialize();
	engine->Load();
	for (int i = 0; i < 5; ++i) {  
		engine->GameLoop();
	}
	engine->Destroy();

	return 0;

}

