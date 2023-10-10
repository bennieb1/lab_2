#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Scene.h"
#include <list>
#include <string>




class SceneManager
{

private:

	std::list<Scene*>scenes;

public:

	SceneManager();
	~SceneManager();

	void Initilize();
	void Destroy();
	void Update();
	void AddScene(Scene* _scene);
	void RemoveScene(Scene* _scene);
	void Load(const std::string& filepath);


};

#endif // !SCENEMANAGER_H