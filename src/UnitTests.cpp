#define CATCH_CONFIG_MAIN
#include "GrabBag.h"
#include "catch.hpp"
#include <limits>
#include <stdexcept>
#include <string>

#define PASSTEST REQUIRE(1==1); return
#define FAILTEST REQUIRE(0!=0); return

TEST_CASE( "A new GrabBag is empty", "[attributes]" ) {
    GrabBag<double> bag;
    
    REQUIRE( bag.size() == 0 );
    REQUIRE( bag.empty() );
}

TEST_CASE( "A GrabBag with one element has a size of one", "[attributes]" ) {
    GrabBag<float> bag;
    
    bag.insert(3.141592653589793f);
    
    REQUIRE( bag.size() == 1 );
    REQUIRE( bag.empty() == false );
}

TEST_CASE( "A GrabBag that had one element grabbed has a size of zero", "[attributes]" ) {
    GrabBag<float> bag;
    
    bag.insert(3.141592653589793f);
    bag.grab();
    REQUIRE( bag.size() == 0 );
    REQUIRE( bag.empty() );
}

TEST_CASE( "A GrabBag with two elements has a size of two", "[attributes]" ) {
    GrabBag<unsigned> bag;
    
    bag.insert({2,999});
    
    REQUIRE( bag.size() == 2 );
    REQUIRE( bag.empty() == false );
}

TEST_CASE( "Inserting and grabbing an element from a GrabBag returns the same element", "[interactions]") {
    GrabBag<std::string> bag;
    
    bag.insert("Hello, bag!");
    
    std::string object = bag.grab();
    REQUIRE( object == "Hello, bag!" );
}

TEST_CASE( "Inserting two and grabbing two elements from a GrabBag returns the same elements", "[interactions]") {
    GrabBag<short> bag;
    
    bag += {-2,2};
    
    short object = bag.grab();
    
    REQUIRE( bag.size() == 1 );
    REQUIRE( bag.empty() == false );
        
    if (object == -2) 
        REQUIRE ( bag.grab() == 2 );
    else if (object == 2)
        REQUIRE ( bag.grab() == -2 );
    else
        FAILTEST;
}

TEST_CASE( "Inserting and grabbing one hundred elements within a range from a GrabBag returns elements in that range", "[interactions]") {
    GrabBag<int> bag;
    
    for (int i = 0; i < 100; ++i)
        bag += i;
    
    while (bag.empty() == false)
        REQUIRE (bag.grab() < 100);
}

TEST_CASE( "GrabBag content can be instantiated with a vector", "[interactions]") {
    std::vector<std::size_t> vec = {2,2,2,2,2,2,2};
    GrabBag<std::size_t> bag(vec);
    
    REQUIRE(bag.size() == vec.size());
    
    while (bag.empty() == false)
        REQUIRE (bag.grab() == 2);
}

TEST_CASE( "GrabBag content can be instantiated and appended with an initializer list", "[interactions]") {
    GrabBag<std::size_t> bag({2,2,2,2,2,2,2});
    bag += {2,2,2,2};
    REQUIRE(bag.size() == 11);
    
    while (bag.empty() == false)
        REQUIRE (bag.grab() == 2);
}

TEST_CASE( "GrabBag content can be instantiated and appended with another GrabBag", "[interactions]") {
    GrabBag<char> first({22,13,52,22,12});
    GrabBag<char> second = first;
    
    REQUIRE(first.size() == 5);
    REQUIRE(first.size() == second.size());

    int sizeCheck = 0;
    while (!first.empty()) {
        first.grab();
        ++sizeCheck;
    }
    
    REQUIRE(sizeCheck == 5);
            
    sizeCheck = 0;
    while (!second.empty()) {
        second.grab();    
        ++sizeCheck;
    }
    
    REQUIRE(sizeCheck == 5);
}

TEST_CASE( "GrabBag content can be copy-constructed from another GrabBag", "[interactions]") {
    GrabBag<char> first({22,13,52,22,12});
    GrabBag<char> second(first);
    
    REQUIRE(first.size() == second.size());
        
    for (int i = 0; i < first.size(); ++i)
        first.grab();
        
    for (int i = 0; i < second.size(); ++i)
        second.grab();    
}

TEST_CASE( "Grabbing from an empty GrabBag throws an expection", "[edge_cases]" ) {
    GrabBag<int> bag;
    
    try {
        bag.grab();
    } catch (std::out_of_range& e) {
        PASSTEST;
    }
    FAILTEST;
}

