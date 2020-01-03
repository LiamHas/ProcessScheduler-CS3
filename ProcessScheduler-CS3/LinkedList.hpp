

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.hpp"
#include "LinkedListNode.hpp"

template <class item_t>
class LinkedList : public List<item_t>
{
    protected:
        LinkedListNode<item_t>* head;
        LinkedListNode<item_t>* tail;
        int size;
    
    public:
        LinkedList();
        virtual ~LinkedList();
        virtual void pushBack(const item_t& item);
        virtual void popBack();
        virtual const item_t& getBack() const;
        virtual void pushFront(const item_t& item);
        virtual void popFront();
        virtual const item_t& getFront() const;
        virtual const item_t& getItem(int index) const;
        virtual void setItem(int index, const item_t& item);
        virtual void insert(int index, const item_t& item);
        virtual void remove(int index);
        virtual int getSize() const;
        virtual bool isEmpty() const;

};

#include "LinkedList.tpp"

#endif /* LinkedList_hpp */
