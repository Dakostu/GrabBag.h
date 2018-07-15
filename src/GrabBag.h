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
    GrabBag(const GrabBag<T> &secondBag);
    
    void insert(T object);
    void insert(const std::vector<T> &objects);
    T grab();
    std::size_t size();
    bool empty();    
    void operator+=(T e);
    void operator+=(const std::vector<T> &vec);
};

// Class Definition -------------------------------------------------
/**
 * Default constructor.
 * New, empty vector is instantiated, size is set to zero.
 */
template <class T>
GrabBag<T>::GrabBag() {
    bagSize = 0;
}

/**
 * Constructor with vector as parameter.
 * GrabBag vector gets assigned to vector reference, size is set to vector size.
 */
template <class T>
GrabBag<T>::GrabBag(const std::vector<T> &vec) {    
    bag = vec;
    bagSize = vec.size();
}

/**
 * Copy constructor with GrabBag as parameter.
 * This copies the attributes of the GrabBag parameter to this instance.
 */
template <class T>
GrabBag<T>::GrabBag(const GrabBag<T> &secondBag) {    
    bag = secondBag.bag;
    bagSize = secondBag.bagSize;
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

/**
 * Assignment addition operator with T element
 * Just a fancy way to call insert(T object)
 */
template <class T> 
void GrabBag<T>::operator+=(T e){
    this->insert(e);
}

/**
 * Assignment addition operator with vector parameter
 */
template <class T> 
void GrabBag<T>::operator+=(const std::vector<T> &vec){
    this->insert(vec);
}



#endif
