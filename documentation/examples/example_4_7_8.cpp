#include "../../src/GrabBag.h"
#include <iostream>

template <class T>
void outputSize(GrabBag<T> &bag) {
    
    std::cout << "Amount of bag elements: " << bag.size() << std::endl;
    
}

int main() {

    GrabBag<float> bag({1.02, 1.00, 4.24252});
    
    // decreasing GrabBag size will be displayed
    while (!bag.empty()) {
        outputSize(bag);
        bag.grab();
    }
    outputSize(bag);

}
