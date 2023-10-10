#include "AssetManager.h"
#include <iostream>



AssetManager::AssetManager() {

	//construct logic here

}

AssetManager::~AssetManager() {

	std::cout << "AssetManager destroyed " << std::endl;
	
}

void AssetManager::initilize() {

	std::cout << "Assets Initilized" << std::endl;

}

void AssetManager::Load() {

	std::cout << "Load assetManager" << std::endl;
}

void AssetManager::Update() {
		
	std::cout << "Update assetManager" << std::endl;

}

void AssetManager::Destroy() {

	
	std::cout << "AssetManager destroyed " << std::endl;

}