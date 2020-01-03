

#include <stdio.h>
#include <iostream>
#include "ArrayList.hpp"
using namespace std;

template <class item_t>
ArrayList<item_t>::ArrayList()
{
    items = new item_t[10];
    size = 0;
    capacity = 10;
}

template <class item_t>
ArrayList<item_t>::ArrayList(int capacity)
{
    size = 0;
    item_t* a = new item_t[capacity];
    items = a;
    this->capacity = capacity;
    
}
template <class item_t>
ArrayList<item_t>::~ArrayList()
{
    delete[] items;
}

template <class item_t>
void ArrayList<item_t>::pushBack(const item_t& item)
{
    if(size == capacity-1)
    {
        item_t* newList = new item_t[size*2];
        
        for (int i = 0; i < size; i++)
        {
            newList[i] = items[i];
        }
        newList[size] = item;
        
        delete[] items;
        
        items = newList;
        size++;
        capacity = size*2;
        
    }
    else
    {
        items[size] = item;
        size++;
    }
    
    
}

template <class item_t>
void ArrayList<item_t>::popBack()
{
    size--;
}

template <class item_t>
const item_t& ArrayList<item_t>::getBack() const
{
    return items[size-1];
}

template <class item_t>
void ArrayList<item_t>::pushFront(const item_t& item)
{
    if(size == capacity-1)
    {
        item_t* newList = new item_t[size*2];
        newList[0] = item;
        
        for (int i = 1; i < size+1; i++)
        {
            newList[i] = items[i-1];
        }
        
        delete[] items;
        
        items = newList;
        size++;
        capacity = size*2;
        
        delete[] newList;

    }
    else if(size == 0)
    {
        items[0] = item;
        size++;
    }
    else
    {
        for (int i = size; i > 0; i--)
        {
            items[i] = items[i-1];
        }
        items[0] = item;
        size++;

    }

}

template <class item_t>
void ArrayList<item_t>::popFront()
{
    for(int i = 0; i < size-1; i++)
    {
        items[i] = items[i+1];
    }
    size--;
}

template <class item_t>
const item_t& ArrayList<item_t>::getFront() const
{
    return items[0];
}

template <class item_t>
const item_t& ArrayList<item_t>::getItem(int index) const
{
    return items[index];
}

template <class item_t>
void ArrayList<item_t>::setItem(int index, const item_t& item)
{
    items[index] = item;
}

template <class item_t>
void ArrayList<item_t>::insert(int index, const item_t& item)
{
    if(index == size)
    {
        pushBack(item);
    }
    else if(index == 0)
    {
        pushFront(item);
    }
    else if(size == capacity-1)
    {
        item_t* newList = new item_t[size*2];
        for(int i = 0; i< size+1; i++)
        {
            if(i == index)
            {
                newList[i] = item;
            }
            else if(i > index)
            {
                newList[i] = items[i-1];
            }
            else
            {
                newList[i] = items[i];
            }
        }
        
        delete[] items;
        
        items = newList;
        size++;
        capacity = size*2;
    }
    else
    {
        for(int i = size; i >= 0; i--)
        {
            if(i == index)
            {
                items[i] = item;
            }
            else if(i > index)
            {
                items[i] = items[i-1];
            }
            else
            {
                items[i] = items[i];
            }
        }
        size++;

    }
    
}

template <class item_t>
void ArrayList<item_t>::remove(int index)
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
        for (int i = 0; i < size-1; i++)
        {
            if(i >= index)
            {
                items[i] = items[i+1];
            }
            else
            {
                items[i] = items[i];
            }
        }
        size--;
    }
}

template <class item_t>
int ArrayList<item_t>::getSize() const
{
    return size;
}

template <class item_t>
bool ArrayList<item_t>::isEmpty() const
{
    if(size == 0)
    {
        return true;
    }
    return false;
}

template <class item_t>
int ArrayList<item_t>::getCapacity() const
{
    return capacity;
}















































