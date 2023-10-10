#include "SceneManager.h"
#include <iostream>
#include "json.hpp"
#include <fstream>


SceneManager::SceneManager() {

	std::cout << "SCENEMANAGER CREATED" << std::endl;
}

SceneManager::~SceneManager() {

	std::cout << "SCENEMANAGER Destroyed" << std::endl;

}

void SceneManager::Initilize() {

	std::cout << "SCENEMANAGER INITIALIZED" << std::endl;


}

void SceneManager::Destroy() {

	std::cout << "SCENEMANAGER DESTROYED" << std::endl;
	for (Scene* scene : scenes) {
		delete scene;
	}
	scenes.clear();

}

void SceneManager::AddScene(Scene* _scene) {


	scenes.push_back(_scene);
	std::cout << "ADDED NEW SCENE" << std::endl;


}

void SceneManager::RemoveScene(Scene* _scene) {

	std::cout << "REMOVED NEW SCENE" << std::endl;
}

void SceneManager::Update() {
	std::cout << "updated scenemanager" << std::endl;
}

void SceneManager::Load(const std::string& filepath) { // Gets file GameLevelExample and parses till it finds scene name then passes to scene class
	std::ifstream inputStream(filepath);
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	std::string name;


	if (document.hasKey("SceneManager")) {
		for (auto& scene : document["SceneManager"].ArrayRange()) {
			std::string name;

			if (scene.hasKey("name")) {
				name = scene["name"].ToString();
				std::cout << "Scene Name: " << name << std::endl;

				// Assuming Scene has a Load function that accepts the name
				// This should probably load other data like entities, etc. instead of just the name
				Scene* Scene1 = new Scene();
				Scene1->Load(scene);
			}





		}


	}


}