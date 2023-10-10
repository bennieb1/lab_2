#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H
#include "json.hpp"
#include <fstream>

class Component
{

private:
	int id = 0;

public:
	Component();
	~Component();

	void initilize();
	void Destroy();
	int GetComponentId();
	void Update();
	void Load(json::JSON& _json);



};

#endif 

