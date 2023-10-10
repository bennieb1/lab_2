#include "Object.h"
#include <iostream>



Object::Object() {
    std::cout << "Object constructed."<<std::endl;

}

Object::~Object() {
    std::cout << "Object destroyed."<<std::endl;

}

void Object::Destroy() {
    if (initilized) {
        std::cout << "Object destroyed by Destroy method.\n";
        // Add your specific destruction logic here
        initilized = false;
    }
    else {
        std::cout << "Object already destroyed or not initialized.\n";
    }

}

void Object::initilize() {
    if (!initilized) {
        std::cout << "Object initialized.\n";
        // Add your specific initialization logic here
        initilized = true;
    }
    else {
        std::cout << "Object already initialized.\n";
    }

}


bool Object::isInitilized() {
    return initilized;

}


void Object::Load() {
    if (initilized) {
        std::cout << "Loading object...\n";
        // Add your specific loading logic here
    }
    else {
        std::cout << "Object not initialized. Cannot load.\n";
    }


}