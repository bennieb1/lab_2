#include "Entity.h"
#include <list>
#include <string>


Entity::Entity()  {}

// Destructor
Entity::~Entity() {
    Destroy();
}

// Method to initialize the entity
void Entity::Initialize() {
    // Add initialization code here
}

// Method to destroy the entity
void Entity::Destroy() {
    for (Component* component : components) {
        delete component; // Freeing the memory allocated for components
    }
    components.clear();
}

// Method to add a component to the entity
void Entity::AddComponent(Component* component) {
    components.push_back(component);
}

// Method to remove component from entity
void Entity::RemoveComponent(Component* component) {
    components.remove(component);
    delete component;
}

// Method to update entity
void Entity::Update() {
    // Add update code here
}

// Method to get the name of the entity
std::string Entity::GetName() const {
    return name;
}

// Load method (not defined in the class diagram, so it's left empty here)
void Entity::Load(json::JSON& _json) {
    // Add loading code here
}