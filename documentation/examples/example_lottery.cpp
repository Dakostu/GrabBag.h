#include "../../src/GrabBag.h"
#include <iostream>
#include <set>


int main() {
    GrabBag<int> enalotto;
    std::set<int> mainNumbers;
    int jolly, superStar;
    
    for (int i = 1; i <= 90; ++i)
        enalotto.insert(i);
    
    for (int j = 0; j < 6; ++j)
        mainNumbers.insert(enalotto.grab());
    
    jolly = enalotto.grab();
    superStar = enalotto.grab();
    
    // Output Main Numbers
    std::cout << "Main Numbers: ";
    for (int number : mainNumbers)
        std::cout << number << " ";
    std::cout << std::endl;
    
    // Output Jolly & SuperStar numbers
    std::cout << "Jolly: " << jolly << std::endl;
    std::cout << "SuperStar: " << superStar << std::endl;
}
