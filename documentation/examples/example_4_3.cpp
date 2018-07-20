#include "../../src/GrabBag.h"
#include <iostream>
#include <vector>

int main() {

    GrabBag<double> original({3.142, 4.20});
    GrabBag<double> clone(original);
    
    // will output "true"
    std::cout << std::boolalpha << (original.size() == clone.size()) << std::endl;
    
    // will output all two elements of original GrabBag
    while (!original.empty())
        std::cout << original.grab() << std::endl;
    
    // will output all two elements of clone GrabBag
    // (de facto the same numbers)
    while (!clone.empty())
        std::cout << clone.grab() << std::endl;

}
