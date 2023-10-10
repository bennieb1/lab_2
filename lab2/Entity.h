#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Component.h"
#include <list>
#include <string>
#include "json.hpp"

class Entity
{
private:
    std::list<Component*> components; // List to store components
    std::string name;                 // Name of the entity


public:
    // Constructor
    Entity();

    // Destructor
    ~Entity();

    // Method to initialize the entity
    void Initialize();

    // Method to destroy the entity
    void Destroy();

    // Method to add a component to the entity
    void AddComponent(Component* component);
    // Method to remove a component from the entity
    void RemoveComponent(Component* component);

    // Method to update the entity
    void Update();

    // Method to get the name of the entity
    std::string GetName() const;

    // Load method (not defined in the class diagram, so it's left empty here)
    void Load(json::JSON& _json);


};
#endif // !ENTITY_H
