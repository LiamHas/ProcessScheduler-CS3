
#include <stdio.h>
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

template <class item_t>
LinkedList<item_t>::LinkedList()
{
    head = 0;
    tail = 0;
    size = 0;
    
}

template <class item_t>
LinkedList<item_t>::~LinkedList()
{
    LinkedListNode<item_t>* temp = head;

    for(int i = 0; i < size; i++)
    {
        LinkedListNode<item_t>* temp2 = temp->getNext();
        delete temp;
        temp = temp2;
    }
    tail = 0;
}

template <class item_t>
void LinkedList<item_t>::pushBack(const item_t& item)
{
    LinkedListNode<item_t>* itemNode = new LinkedListNode<item_t>(0, item);
    if(size == 0)
    {
        head = itemNode;
        tail = itemNode;
        size++;
        
    }
    else
    {
        tail->setNext(itemNode);
        tail = itemNode;
        size++;
    }
  
    
}
template <class item_t>
void LinkedList<item_t>::popBack()
{
    if(size == 1)
    {
        head = 0;
        tail = 0;
        size = 0;
    }
    else
    {
        LinkedListNode<item_t>* a = head;
        while(a->getNext() != tail)
        {
            a = a->getNext();
        }
        tail = a;
        tail->setNext(0);
        size--;
    }
    
}

template <class item_t>
const item_t& LinkedList<item_t>::getBack() const
{
    return tail->getItem();
}

template <class item_t>
void LinkedList<item_t>::pushFront(const item_t& item)
{
    if(size == 0)
    {
        LinkedListNode<item_t>* itemNode = new LinkedListNode<item_t>(0, item);
        head = itemNode;
        tail = itemNode;
        size++;
        
    }
    else
    {
        LinkedListNode<item_t>* itemNode = new LinkedListNode<item_t>(head, item);
        head = itemNode;
        size++;
    }
}

template <class item_t>
void LinkedList<item_t>::popFront()
{
    if(size == 1)
    {
        head = 0;
        tail = 0;
        size = 0;
    }
    else
    {
        head = head->getNext();
        size--;
    }
}

template <class item_t>
const item_t& LinkedList<item_t>::getFront() const
{
    return head->getItem();
}

template <class item_t>
const item_t& LinkedList<item_t>::getItem(int index) const
{
    if(index == 0)
    {
        return head->getItem();
    }
    else if(index == size-1)
    {
        return tail->getItem();
    }
    else
    {
        LinkedListNode<item_t>* a = head;
        for(int i = 0; i < index; i++)
        {
            a = a->getNext();
        }
        return a->getItem();
    }
}

template <class item_t>
void LinkedList<item_t>::setItem(int index, const item_t& item)
{
    if(index == 0)
    {
        head->setItem(item);
    }
    else if(index == size-1)
    {
        tail->setItem(item);
    }
    else
    {
        LinkedListNode<item_t>* a = head;
        for(int i = 0; i < index; i++)
        {
            a = a->getNext();
        }
        a->setItem(item);
    }
}

template <class item_t>
void LinkedList<item_t>::insert(int index, const item_t& item)
{
    if(index == 0)
    {
        pushFront(item);
    }
    else if(index == size)
    {
        pushBack(item);
    }
    else
    {
        LinkedListNode<item_t>* a = head;
        for(int i = 0; i < index-1; i++)
        {
            a = a->getNext();
        }
        LinkedListNode<item_t>* itemNode = new LinkedListNode<item_t>(a->getNext(), item);
        a->setNext(itemNode);
        size++;
    }
}

template <class item_t>
void LinkedList<item_t>::remove(int index)
{
    if(index == 0)
    {
        popFront();
    }
    else if(index == size-1)
    {
        popBack();
    }
    else
    {
        LinkedListNode<item_t>* a = head;
        for(int i = 0; i < index-1; i++)
        {
            a = a->getNext();
        }
        LinkedListNode<item_t>* removed = a->getNext();

        a->setNext(removed->getNext());
        size--;
        
        delete removed;
    }
}

template <class item_t>
int LinkedList<item_t>::getSize() const
{
    return size;
}

template <class item_t>
bool LinkedList<item_t>::isEmpty() const
{
    if(head == 0)
    {
        return true;
    }
    return false;
}
