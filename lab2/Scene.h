#pragma once

#ifndef SCENE_H
#define SCENE_H
#include <list>
#include <string>
#include "Entity.h"
#include "json.hpp"
#include <fstream>


class Scene
{
private:
	std::list<Entity*> entities;

public:
	Scene();
	~Scene();
	void initilize();
	void Destroy();
	void Update();
	void AddEntry(Entity* _entity);
	void RemoveEntry(Entity* _entity);
	void Load(json::JSON& _json);


};
#endif // !SCENE_H
