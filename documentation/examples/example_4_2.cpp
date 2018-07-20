#include "../../src/GrabBag.h"
#include <iostream>
#include <vector>

int main() {

    std::vector<int> v = {2,3,12,52};
    GrabBag<int> bagFromVector(v);
    
    // will output "4"
    std::cout << v.size() << std::endl; 

}
