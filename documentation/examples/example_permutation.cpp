#include "../../src/GrabBag.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cerr << "Need a string argument" << std::endl;
        return 1;
    }
    
    // Program argument parameter is input string    
    std::string input(argv[1]);
    std::string output;
    GrabBag<char> word;
        
    // Insert single char from input string into GrabBag
    for (char c : input)
        word += c;
    
    // Fill output string with random char
    while (!word.empty())
        output += word.grab();
    
    std::cout << output << std::endl;
}
