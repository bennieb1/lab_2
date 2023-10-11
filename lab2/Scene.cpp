#include "Scene.h"
#include <iostream>
#include "json.hpp"

Scene::Scene() 
{
	
	std::cout << "SCENE CREATED" << std::endl;

}

Scene::~Scene() 
{
	
	std::cout << "SCENE Destroyed" << std::endl;

}

void Scene::initilize() 
{

	std::cout << "SCENE INITIALIZED" << std::endl;



}

void Scene::Destroy() 
{

	std::cout << "SCENE DESTROYED" << std::endl;
	Entity* entity = new Entity();

	entity->Destroy();
	entities.clear();

}

void Scene::Update() 
{

	std::cout << "SCENE UPDATED" << std::endl;
	Entity* entity = new Entity();

	entity->Update();
	


}

void Scene::AddEntry(Entity* _entity) 
{

	entities.push_back(_entity);

}

void Scene::RemoveEntry(Entity* _entity) 
{
	entities.remove(_entity);

}


void Scene::Load(json::JSON& _json) 
{
	
	if (_json.hasKey("name")) {
	
		std::string name;

		if (_json.hasKey("name")) {
			name = _json["name"].ToString();
			std::cout << "Scene Name: " << name << std::endl;

			Entity* entites = new Entity();
			entites->Load(_json);
		}
		

	}







	
	




	
	

}
