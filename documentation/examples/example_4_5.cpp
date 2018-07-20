#include "../../src/GrabBag.h"
#include <iostream>
#include <vector>

int main() {

    GrabBag<unsigned> bag({1,1,1,1,1});
    std::vector<unsigned> vec = {2,2,2,2,2};
    
    bag.insert(vec);
    
    // will output ones and twos
    while (!bag.empty())
        std::cout << bag.grab() << std::endl;

}
