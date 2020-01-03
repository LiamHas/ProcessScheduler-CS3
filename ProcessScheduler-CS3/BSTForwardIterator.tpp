
#include <stdio.h>
#include "BSTForwardIterator.hpp"
#include <string>
#include <iostream>

using namespace std;

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t>::BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel)
{
    this->sentinel = sentinel;
    current = node;
}

template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::next()
{
    if(current == sentinel)
    {
        return;
    }
    
    BSTNode<key_t, val_t>* x = current;

    if(x->getRightChild() != sentinel)
    {
        x = x->getRightChild();
        while(x->getLeftChild() != sentinel)
        {
            x = x->getLeftChild();
        }
        current = x;
        
    }
    else
    {
        
        BSTNode<key_t, val_t>* y = current->getParent();
        
        while(y != sentinel && x == y->getRightChild())
        {
            x = y;
            y = y->getParent();
        }
        current = y;
    }

    
}

template <class key_t, class val_t>
bool BSTForwardIterator<key_t, val_t>::isPastEnd() const
{
    if(current == sentinel)
    {
        return true;
    }
    return false;
}
    
template <class key_t, class val_t>
const key_t& BSTForwardIterator<key_t, val_t>::getKey() const
{
    return current->getKey();
}
    
template <class key_t, class val_t>
const val_t& BSTForwardIterator<key_t, val_t>::getValue() const
{
    return current->getValue();
}
    
template <class key_t, class val_t>
void BSTForwardIterator<key_t, val_t>::setValue(const val_t& newVal)
{
    current->setValue(newVal);
}
    

