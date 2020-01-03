
#include "BSTNode.hpp"

template <class key_t, class val_t>
BSTNode<key_t, val_t>::BSTNode(const key_t& k, const val_t& v)
{
    key = k;
    val = v;
    
    parent = 0;
    lChild = 0;
    rChild = 0;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>::~BSTNode()
{
    
}

template <class key_t, class val_t>
const val_t& BSTNode<key_t, val_t>::getValue() const
{
    return val;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setValue(const val_t& v)
{
    val = v;
}

template <class key_t, class val_t>
const key_t& BSTNode<key_t, val_t>::getKey() const
{
    return key;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setKey(const key_t& k)
{
    key = k;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getLeftChild() const
{
    return lChild;
}

template <class key_t, class val_t>
void  BSTNode<key_t, val_t>::setLeftChild(BSTNode<key_t, val_t>* bst)
{
    lChild = bst;
}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getRightChild() const
{
    return rChild;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setRightChild(BSTNode<key_t, val_t>* bst)
{
    rChild = bst;

}

template <class key_t, class val_t>
BSTNode<key_t, val_t>* BSTNode<key_t, val_t>::getParent() const
{
    return parent;
}

template <class key_t, class val_t>
void BSTNode<key_t, val_t>::setParent(BSTNode<key_t, val_t>* bst)
{
    parent = bst;
}
