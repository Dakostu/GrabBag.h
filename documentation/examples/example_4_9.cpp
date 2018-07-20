#include "../../src/GrabBag.h"
#include <iostream>

int main() {

    GrabBag<char> first({'a','e','i','o','u'});
    GrabBag<char> second = first;
    
    // output will be "true"
    std::cout << std::boolalpha << (first.size() == second.size()) << std::endl;
        
    while (!first.empty())
        std::cout << first.grab() << std::endl;
    
    std::cout << "-----------------------" << std::endl;
    
    // output will contain the same elements as the first GrabBag
    while (!second.empty())
        std::cout << second.grab() << std::endl;
}
