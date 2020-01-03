

#include "BSTMultimap.hpp"
#include <string>
#include <iostream>
#include <queue>

using namespace std;

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::BSTMultimap()
{
    sentinel = 0;
    root = sentinel;
    numItems = 0;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& val)
{
    BSTNode<key_t, val_t>* newNode = new BSTNode<key_t, val_t>(key, val);
    newNode->setParent(sentinel);
    newNode->setLeftChild(sentinel);
    newNode->setRightChild(sentinel);

    insertNode(newNode);

}
template <class key_t, class val_t>
int BSTMultimap<key_t, val_t>::getSize()
{
    return numItems;
}

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::isEmpty()
{
    if(root == sentinel)
    {
        return true;
    }
    return false;
}

/*template <class key_t, class val_t>
string BSTMultimap<key_t, val_t>::toString()
{
    
    queue<BSTNode<key_t, val_t>*> q;
    string str;
    if(root != 0)
    {
        q.push(root);
    }
    while(q.empty() == false)
    {
        key_t k = q.front()->getKey();
        val_t v = q.front()->getValue();
            
        string sk = to_string(k);
        string sv = to_string(v);
        
        str += " (" + sk  + " : " + sv + ") ";
        
        if(q.front()->getLeftChild() != 0)
        {
            q.push(q.front()->getLeftChild());
        }
        if(q.front()->getRightChild() != 0)
        {
            q.push(q.front()->getRightChild());

        }
        q.pop();
    }
    
    return str;
}
*/

template <class key_t, class val_t>
bool BSTMultimap<key_t, val_t>::contains(const key_t& key) const
{
    BSTNode<key_t, val_t>* x = root;

    if(x != sentinel)
    {
        while(x != sentinel && x->getKey() != key)// && (x->getRightChild() != sentinel || x->getLeftChild() != sentinel))
        {
            if(key < x->getKey())
            {
                x = x->getLeftChild();
            }
            else
            {
                x = x->getRightChild();
            }
        }
        if(x != sentinel)
        {
            if (key == x->getKey())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::clear()
{
    queue<BSTNode<key_t, val_t>*> q;
    if(root != sentinel)
    {
        q.push(root);
    }
    while(q.empty() == false)
    {
        if(q.front()->getLeftChild() != sentinel)
        {
            q.push(q.front()->getLeftChild());
        }
        if(q.front()->getRightChild() != sentinel)
        {
            q.push(q.front()->getRightChild());
            
        }
        delete q.front();
        q.pop();
        
    }
    
    numItems = 0;
    root = sentinel;
}

template <class key_t, class val_t>
BSTMultimap<key_t, val_t>::~BSTMultimap()
{
    clear();
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMin() const
{
    BSTNode<key_t, val_t>* x = root;
    if(x == sentinel)
    {
        x = sentinel;
        BSTForwardIterator<key_t, val_t> w(x,sentinel);
        return w;
    }
    
    while(x->getLeftChild() != sentinel)
    {
        x = x->getLeftChild();
    }

    BSTForwardIterator<key_t, val_t> z(x, sentinel);
    
    return z;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::getMax() const
{
    BSTNode<key_t, val_t>* x = root;
    if(x == sentinel)
    {
        x = sentinel;
        BSTForwardIterator<key_t, val_t> w(x,sentinel);
        return w;
    }
    
    while(x->getRightChild() != sentinel)
    {
        x = x->getRightChild();
    }
    BSTForwardIterator<key_t, val_t> z(x, sentinel);
    
    return z;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findFirst(const key_t& key) const
{
    BSTNode<key_t, val_t>* x = root;
    
    queue<BSTNode<key_t, val_t>*> q;
    
    while(x != sentinel)
    {
        if(x != sentinel)
        {
            if(x->getKey() ==key)
            {
                q.push(x);
            }
        }
        
        if(key < x->getKey())
        {
            x = x->getLeftChild();
        }
        else
        {
            x = x->getRightChild();
        }
        
    }
    
    if(q.empty())
    {
        BSTForwardIterator<key_t, val_t> emptyT(sentinel, sentinel);
        return emptyT;
    }
    BSTForwardIterator<key_t, val_t> qIter(q.front(), sentinel);
    return qIter;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::findLast(const key_t& key) const
{
    BSTNode<key_t, val_t>* x = root;
        
    BSTNode<key_t, val_t>** lastArray = new BSTNode<key_t, val_t>*[numItems];
    
    int i = 0;
    while(x != sentinel)
    {
        if(x != sentinel)
        {
            if(x->getKey() ==key)
            {
                i++;
                lastArray[i] = x;
            }
        }
        
        if(key < x->getKey())
        {
            x = x->getLeftChild();
        }
        else
        {
            x = x->getRightChild();
        }
        
    }
    
    if(i == 0)
    {
        BSTForwardIterator<key_t, val_t> emptyT(sentinel, sentinel);
        return emptyT;
    }
    BSTForwardIterator<key_t, val_t> qIter(lastArray[i], sentinel);
    return qIter;
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
    numItems--;
    BSTNode<key_t, val_t>* target = pos.current;
    
    BSTForwardIterator<key_t, val_t> q = pos;
    q.next();
    BSTForwardIterator<key_t, val_t> z(q.current, sentinel);

    
    if(target->getLeftChild() == sentinel)
    {
        BSTNode<key_t, val_t>* right = target->getRightChild();
        
        if(target->getParent() == sentinel)
        {
            root = right;
        }
        else if(target->getParent()->getLeftChild() == target)
        {
            target->getParent()->setLeftChild(right);
        }
        else
        {
            target->getParent()->setRightChild(right);
        }
        if(right != sentinel)
        {
            right->setParent(target->getParent());

        }

    }
    else if(target->getRightChild() == sentinel)
    {
        BSTNode<key_t, val_t>* left = target->getLeftChild();
        
        if(target->getParent() == sentinel)
        {
            root = left;
        }
        else if(target->getParent()->getLeftChild() == target)
        {
            target->getParent()->setLeftChild(left);
        }
        else
        {
            target->getParent()->setRightChild(left);
        }
        if(left != sentinel)
        {
            left->setParent(target->getParent());
        }

    }
    
    else
    {

        BSTNode<key_t, val_t>* righty = target->getRightChild();

        while(righty->getLeftChild() != sentinel)
        {
            righty = righty->getLeftChild();
        }

        BSTForwardIterator<key_t, val_t> yIter(righty, sentinel);

        BSTNode<key_t, val_t>* y = yIter.current;

        if(y->getParent() != target)
        {
            BSTNode<key_t, val_t>* yRight = y->getRightChild();
            
            if(y->getParent() == sentinel)
            {
                root = yRight;
                cout<<yRight->getKey()<<endl;

            }
            else if(y->getParent()->getLeftChild() == y)
            {
                y->getParent()->setLeftChild(yRight);
            }
            else
            {
                y->getParent()->setRightChild(yRight);
            }
            if(yRight != sentinel)
            {
                yRight->setParent(y->getParent());
            }
            y->setRightChild(target->getRightChild());
            y->getRightChild()->setParent(y);
        }

        if(target->getParent() == sentinel)
        {
            root = y;
        }
        else if(target->getParent()->getLeftChild() == target)
        {
            target->getParent()->setLeftChild(y);
        }
        else
        {
            target->getParent()->setRightChild(y);
        }
        if(y != sentinel)
        {
            y->setParent(target->getParent());
        }
        
        y->setLeftChild(target->getLeftChild());
        y->getLeftChild()->setParent(y);
        
    }
    return z;
}

template <class key_t, class val_t>
void BSTMultimap<key_t, val_t>::insertNode(BSTNode<key_t, val_t>* newNode)
{
    BSTNode<key_t, val_t>* y = sentinel;
    BSTNode<key_t, val_t>* x = root;
    
    numItems++;
    
    while(x != sentinel)
    {
        y = x;
        if(newNode->getKey() < x->getKey())
        {
            x = x->getLeftChild();
        }
        else
        {
            x = x->getRightChild();
        }
    }
    
    newNode->setParent(y);
    
    if(y == sentinel)
    {
        root = newNode;
    }
    
    else if(newNode->getKey() < y->getKey())
    {
        y->setLeftChild(newNode);
    }
    else
    {
        y->setRightChild(newNode);
    }
}
