#include "../../src/GrabBag.h"
#include <iostream>

int main() {
    
    GrabBag<char*> bag;
    
    // will output "0"
    std::cout << bag.size() << std::endl;
    
    // will output "true"
    std::cout << std::boolalpha << bag.empty() << std::endl; 
    
}
