#ifndef GRABBAG_H
#define GRABBAG_H

#include <cmath>
#include <limits>
#include <random>
#include <stdexcept>
#include <vector>

// Class Declaration -------------------------------------------------
template <class T>
class GrabBag {
    std::vector<T> bag;
    std::size_t bagSize;
    std::size_t getRandomIndex();
    
public:
    GrabBag();
    GrabBag(const std::vector<T> &newBag);
    
    void insert(T object);
    void insert(const std::vector<T> &objects);
    T grab();
    std::size_t size();
    bool empty();    
};

// Class Definition -------------------------------------------------
/**
 * Default constructor.
 * New, empty vector is instantiated, size is set to zero.
 */
template <class T>
GrabBag<T>::GrabBag() {}

/**
 * Constructor with vector as parameter.
 * GrabBag vector gets assigned to vector reference, size is set to vector size.
 */
template <class T>
GrabBag<T>::GrabBag(const std::vector<T> &newBag) {    
    bag = newBag;
    bagSize = newBag.size();
}

/**
 * Insert a single object into a GrabBag. 
 * Throws an exception when GrabBag is full.
 */
template <class T>
void GrabBag<T>::insert(T object) {
    if (this->size() == bag.max_size())
        throw std::out_of_range("Bag is full");
            
    bag.push_back(object);
    ++bagSize;
}

/**
 * Insert several objects into a GrabBag. 
 * Calls insert(T object) iteratively.
 */
template <class T>
void GrabBag<T>::insert(const std::vector<T> &objects) {
    for (T object : objects)
        insert(object);    
}

/**
 * Generates a random number in the range [0, size).
 */
template <class T>
inline std::size_t GrabBag<T>::getRandomIndex() {
    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_real_distribution<> dist(0, bagSize);

    return dist(mt);
}

/**
 * Grabs a random element from a GrabBag. 
 * Throws an exception when bag is empty.
 */
template <class T>
T GrabBag<T>::grab() {
    if (this->empty()) 
        throw std::out_of_range("Bag is empty");
    
    int randomIndex = getRandomIndex();
    
    T selectedObject = bag.at(randomIndex);
    bag.erase(bag.begin() + randomIndex);
    --bagSize;
    
    return selectedObject;
}

/**
 * Gets the amount of elements inside the GrabBag.
 */
template <class T>
std::size_t GrabBag<T>::size() {
    return bagSize;
}

/**
 * Checks if a GrabBag has a size of zero.
 */
template <class T>
bool GrabBag<T>::empty() {
    return (size() == 0); 
}


#endif
