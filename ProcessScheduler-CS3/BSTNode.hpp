
#ifndef BSTNode_hpp
#define BSTNode_hpp

#include <stdio.h>
template <class key_t, class val_t>
class BSTNode
{
    protected:
        key_t key;
        val_t val;
        BSTNode<key_t, val_t>* parent;
        BSTNode<key_t, val_t>* lChild;
        BSTNode<key_t, val_t>* rChild;
    
    public:
        BSTNode(const key_t& k, const val_t& v);
        virtual ~BSTNode();
        virtual const val_t& getValue() const;
        virtual void setValue(const val_t& v);
        virtual const key_t& getKey() const;
        virtual void setKey(const key_t& k);
        virtual BSTNode<key_t, val_t>* getLeftChild() const;
        virtual void setLeftChild(BSTNode<key_t, val_t>* bst);
        virtual BSTNode<key_t, val_t>* getRightChild() const;
        virtual void setRightChild(BSTNode<key_t, val_t>* bst);
        virtual BSTNode<key_t, val_t>* getParent() const;
        virtual void setParent(BSTNode<key_t, val_t>* bst);
};
    
#include "BSTNode.tpp"
#endif /* BSTNode_hpp */
