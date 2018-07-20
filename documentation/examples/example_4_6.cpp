#include "../../src/GrabBag.h"
#include <iostream>

int main() {

    GrabBag<short> bag;
    
    for (int i = 1; i <= 10; ++i)
        bag += i;
    
    // output will be a random sequence of numbers within the range [1,10]
    while (!bag.empty())
        std::cout << bag.grab() << std::endl;

}
