#include "LinkedBag.h"

template<class ItemType> 
LinkedBag<ItemType>::LinkedBag(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType> 
int LinkedBag<ItemType>::getCurrentSize() const{
    return itemCount;
}
    
template<class ItemType> 
bool LinkedBag<ItemType>::isEmpty() const{
    return itemCount == 0;
}
    
template<class ItemType> 
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(headPtr);

    headPtr = newNodePtr;

    itemCount++;

    return true;
}
    
template<class ItemType> 
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
    bool found = false; 
    Node<ItemType>* curPtr = headPtr;

    //find object
    while (!found && (curPtr != nullptr)){
        if(curPtr->getItem() == anEntry){
            found = true;
        }
        else{
            curPtr = curPtr->getNext();
        }
    } 

    //swap with last item
    if (found){
        curPtr->setItem(headPtr->getItem());

        Node<ItemType>* nodeToDeletePtr = headPtr;

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    } 
    return found;
}
    
template<class ItemType> 
void LinkedBag<ItemType>::clear(){
    Node<ItemType>* nodeToDeletePtr = headPtr;

    while(headPtr != nullptr){
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = headPtr;
    }
}
    
template<class ItemType> 
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& newEntry) const{
    int frequency = 0;
    Node<ItemType>* curPtr = headPtr;

    for (int i = 0; i < itemCount && curPtr != nullptr; i++){
        if(curPtr->getItem() == newEntry){
            frequency++;
        }
        curPtr = curPtr->getNext();
    }

    return frequency;
}
    
template<class ItemType> 
bool LinkedBag<ItemType>::contains(const ItemType& newEntry) const{
    return getFrequencyOf(newEntry) > 0;
}

template<class ItemType> 
vector<ItemType> LinkedBag<ItemType>::toVector() const{
    vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;

    for (int i = 0; i < itemCount && curPtr != nullptr; i++){
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
    }

    return bagContents;
}

template<class ItemType> 
LinkedBag<ItemType>::~LinkedBag(){
    clear();
}