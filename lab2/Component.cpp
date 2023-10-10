#include "Component.h"
#include <iostream>


Component::Component() : id(0) {

	std::cout << "COMPONENT CREATED" << std::endl;
}

Component::~Component() {

	std::cout << "COMPONENT Destroyed" << std::endl;


}


void Component::initilize() {


	std::cout << "COMPONENT INITIALIZED" << std::endl;

}

void Component::Destroy() {

	std::cout << "COMPONENT DESTROYED" << std::endl;


}


int Component::GetComponentId() {

	return 0;

}


void Component::Update() {

	std::cout << "COMPONENT UPDATED" << std::endl;

}

void Component::Load(json::JSON& _json) {


	if (_json.hasKey("Components")) {

		for (auto& comp : _json["Components"].ArrayRange()) {

			std::string className = comp["className"].ToString();
			int id = comp["id"].ToInt();
			std::cout << "Component Class: " << className << " ID:" << id << std::endl;
			
			

		}

	}


}