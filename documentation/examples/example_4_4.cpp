#include "../../src/GrabBag.h"
#include <iostream>
#include <string>

int main() {

    GrabBag<std::string> helloBag;
    
    helloBag.insert("Hello");
    helloBag.insert("World");
    
    // output will be either "Hello World" or "World Hello"
    std::cout << helloBag.grab() << " " << helloBag.grab() << std::endl;

}
