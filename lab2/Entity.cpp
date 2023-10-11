#include "Entity.h"
#include <list>
#include <string>


Entity::Entity()  
{

    std::cout << "new Entity" << std::endl;

}


Entity::~Entity() 
{

    std::cout << "Entity Destroyed" << std::endl;

}


void Entity::Initialize() 
{
    std::cout << " Entity Initalized" << std::endl;

}

void Entity::Destroy() 
{


    std::cout << "ENTITY DESTROYED" << std::endl;

    Component* comp = new Component();

    comp->Destroy();
    components.clear();
}


void Entity::AddComponent(Component* component)
{
    components.push_back(component);
}


void Entity::RemoveComponent(Component* component)
{
   
    components.remove(component);
    delete component;
}


void Entity::Update() {

    for (Component* comp : components) 
    {
        comp->Update();
    }

}


std::string Entity::GetName() const 
{

    return name;

}

void Entity::Load(json::JSON& _json) 
{


    for (auto& entity : _json["Entities"].ArrayRange()) {

             std::string entityName = entity["Name"].ToString();
             std::cout << "Entity Name: " << entityName << std::endl;

             Component* comp = new Component();
             comp->Load(entity);

    
    }


}