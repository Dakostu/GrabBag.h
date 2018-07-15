#include "../../src/GrabBag.h"
#include <iostream>
#include <set>

int main() {
    GrabBag<int> enaLottoPool;
    GrabBag<int> superStarPool;
    std::set<int> mainNumbers;
    int jolly, superStar;
    
    for (int i = 1; i <= 90; ++i) {
        enaLottoPool.insert(i);
        superStarPool.insert(i);
    }
    
    for (int j = 0; j < 6; ++j)
        mainNumbers.insert(enaLottoPool.grab());
    
    jolly = enaLottoPool.grab();
    superStar = superStarPool.grab();
    
    // Output Main Numbers
    std::cout << "Main Numbers: ";
    for (int number : mainNumbers)
        std::cout << number << " ";
    std::cout << std::endl;
    
    // Output Jolly & SuperStar numbers
    std::cout << "Jolly: " << jolly << std::endl;
    std::cout << "SuperStar: " << superStar << std::endl;
}
