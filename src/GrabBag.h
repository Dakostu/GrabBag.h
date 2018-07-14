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
#include <iostream>
template <class T>
GrabBag<T>::GrabBag() {
    bagSize = 0;
}

template <class T>
GrabBag<T>::GrabBag(const std::vector<T> &newBag) {    
    bag = newBag;
    bagSize = newBag.size();
}

template <class T>
void GrabBag<T>::insert(T object) {
    if (this->size() == bag.max_size())
        throw std::out_of_range("Bag is full");
            
    bag.push_back(object);
    ++bagSize;
}

template <class T>
void GrabBag<T>::insert(const std::vector<T> &objects) {
    for (T object : objects)
        insert(object);    
}

template <class T>
std::size_t GrabBag<T>::getRandomIndex() {
    std::random_device device;
    std::mt19937 mt(device());
    std::uniform_real_distribution<> dist(0, bagSize);

    return dist(mt);
}

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

template <class T>
std::size_t GrabBag<T>::size() {
    return bagSize;
}

template <class T>
bool GrabBag<T>::empty() {
    return (size() == 0); 
}


#endif
