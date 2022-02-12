#ifndef LINKED_BAG
#define LINKED_BAG

#include <vector>
using namespace std;

#include "BagInterface.h"
#include "node.h"

template<class ItemType> 
class LinkedBag: public BagInterface<ItemType> { 
private:
    Node<ItemType>* headPtr;
    int itemCount;
public: 
    LinkedBag();

    int getCurrentSize() const; 
    bool isEmpty() const; 
    bool add(const ItemType& newEntry); 
    bool remove(const ItemType& newEntry); 
    void clear(); 
    int getFrequencyOf(const ItemType& newEntry) const; 
    bool contains(const ItemType& newEntry) const;
    vector<ItemType> toVector() const;

    ~LinkedBag();
};  
#include "LinkedBag.cpp"
#endif