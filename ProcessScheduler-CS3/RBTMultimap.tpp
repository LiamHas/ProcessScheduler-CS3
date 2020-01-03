#include "RBTMultimap.hpp"
#include <string>
#include <iostream>


template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap()
{
    key_t* k = new key_t();
    val_t* v = new val_t();

    RBTNode<key_t, val_t>* sen = new RBTNode<key_t, val_t>(*k, *v, false);
    this->sentinel = sen;
    this->root = this->sentinel;
        
    delete k;
    delete v;
    
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::~RBTMultimap()
{
    this->clear();
    delete this->sentinel;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode<key_t, val_t>* node)
{
    BSTNode<key_t, val_t>* x = node;
    BSTNode<key_t, val_t>* y = x->getRightChild();
    
    x->setRightChild(y->getLeftChild());
       
    if(y->getLeftChild() != this->sentinel)
    {
        y->getLeftChild()->setParent(x);
    }
    y->setParent(x->getParent());
    
    if(x->getParent() == this->sentinel)
    {
        
        this->root = y;

    }
    else if(x == x->getParent()->getLeftChild())
    {
        x->getParent()->setLeftChild(y);
    }
    else
    {
        x->getParent()->setRightChild(y);
    }
    
    y->setLeftChild(x);
    x->setParent(y);

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode<key_t, val_t>* node)
{
    BSTNode<key_t, val_t>* x = node;
    BSTNode<key_t, val_t>* y = x->getLeftChild();
    
    x->setLeftChild(y->getRightChild());
    
    if(y->getRightChild() != this->sentinel)
    {
        y->getRightChild()->setParent(x);
    }
    y->setParent(x->getParent());
    
    if(x->getParent() == this->sentinel)
    {
        this->root = y;

    }
    else if(x == x->getParent()->getRightChild())
    {
        x->getParent()->setRightChild(y);
    }
    else
    {
        x->getParent()->setLeftChild(y);
    }
    
    y->setRightChild(x);
    x->setParent(y);
    
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode<key_t, val_t>* insertedNode)
{

    RBTNode<key_t, val_t>* z = insertedNode;
    
    RBTNode<key_t, val_t>* y = z;
    
    while(z->getParent()->isRed())
    {
        if(z->getParent() == z->getParent()->getParent()->getLeftChild())
        {
            y = z->getParent()->getParent()->getRightChild();

            if(y->isRed())
            {
                z->getParent()->setIsRed(false);
                y->setIsRed(false);
                z->getParent()->getParent()->setIsRed(true);
                z = z->getParent()->getParent();
            }
            else
            {
                if(z == z->getParent()->getRightChild())
                {
                    z = z->getParent();
                    rotateLeft(z);
                }
                z->getParent()->setIsRed(false);
                z->getParent()->getParent()->setIsRed(true);
                rotateRight(z->getParent()->getParent());
            }
            
        }
        else
        {
            y = z->getParent()->getParent()->getLeftChild();

            if(y->isRed())
            {
                z->getParent()->setIsRed(false);
                y->setIsRed(false);
                z->getParent()->getParent()->setIsRed(true);
                z = z->getParent()->getParent();

            }
            else
            {
                if(z == z->getParent()->getLeftChild())
                {
                    z = z->getParent();
                    rotateRight(z);
                }
                z->getParent()->setIsRed(false);
                z->getParent()->getParent()->setIsRed(true);
                rotateLeft(z->getParent()->getParent());
            }
           
        }

    }
    

    RBTNode<key_t, val_t>* RBroot = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
    RBroot->setIsRed(false);
    this->root = RBroot;

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode)
{
    RBTNode<key_t, val_t>* x = replacementNode;
    
    while(x != this->root && x->isRed() == false)
    {
        if(x == x->getParent()->getLeftChild())
        {
            RBTNode<key_t, val_t>* w = x->getParent()->getRightChild();
            
            if(w->isRed())
            {
                w->setIsRed(false);
                x->getParent()->setIsRed(true);
                rotateLeft(x->getParent());
                w = x->getParent()->getRightChild();
            }
            
            if(w->getLeftChild()->isRed() == false && w->getRightChild()->isRed() == false)
            {
                
                w->setIsRed(true);
                x = x->getParent();
            }
            
            else
            {
        
                if(w->getRightChild()->isRed() == false)
                {
                    w->getLeftChild()->setIsRed(false);
                    w->setIsRed(true);
                    rotateRight(w);
                    w = x->getParent()->getRightChild();
                }

                w->setIsRed(x->getParent()->isRed());
                x->getParent()->setIsRed(false);
                w->getRightChild()->setIsRed(false);
                rotateLeft(x->getParent());
                
                RBTNode<key_t, val_t>* RBroot = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
                this->root = RBroot;
                
                x = RBroot;
            }
            
        }
        else
        {
            RBTNode<key_t, val_t>* w = x->getParent()->getLeftChild();
            
            if(w->isRed())
            {
                w->setIsRed(false);
                x->getParent()->setIsRed(true);
                rotateRight(x->getParent());
                w = x->getParent()->getLeftChild();
            }
            
            if(w->getRightChild()->isRed() == false && w->getLeftChild()->isRed() == false)
            {
                w->setIsRed(true);
                x = x->getParent();
            }
            
            else
            {
                if(w->getLeftChild()->isRed() == false)
                {
                    w->getRightChild()->setIsRed(false);
                    w->setIsRed(true);
                    rotateLeft(w);
                    w = x->getParent()->getLeftChild();
                }
                w->setIsRed(x->getParent()->isRed());
                x->getParent()->setIsRed(false);
                w->getLeftChild()->setIsRed(false);
                rotateRight(x->getParent());
                
                RBTNode<key_t, val_t>* RBroot = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
                this->root = RBroot;
                
                x = RBroot;
            }

        }
    }
    x->setIsRed(false);

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode)
{
    if(nodeToReplace->getParent() == this->sentinel)
    {
        this->root = replacementNode;
    }
    else if(nodeToReplace == nodeToReplace->getParent()->getLeftChild())
    {
        nodeToReplace->getParent()->setLeftChild(replacementNode);
    }
    else
    {
        nodeToReplace->getParent()->setRightChild(replacementNode);
    }
    
    replacementNode->setParent(nodeToReplace->getParent());

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insert(const key_t& key, const val_t& value)
{
    RBTNode<key_t, val_t>* newNode = new RBTNode<key_t, val_t>(key, value, true);
    newNode->setLeftChild(this->sentinel);
    newNode->setRightChild(this->sentinel);
    newNode->setIsRed(true);

    this->insertNode(newNode);
    insertFixup(newNode);
}

template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{
    this->numItems--;
    
    RBTNode<key_t, val_t>* z = dynamic_cast<RBTNode<key_t, val_t>*>(pos.current);
    RBTNode<key_t, val_t>* y = z;
    RBTNode<key_t, val_t>* x = z;

    BSTForwardIterator<key_t, val_t> returnIter(y, this->sentinel);
    returnIter.next();
    BSTForwardIterator<key_t, val_t> returnIter2(y, this->sentinel);

    
    bool ogY = y->isRed();
    
    if(z->getLeftChild() == this->sentinel)
    {
        x = z->getRightChild();
        transplant(z, z->getRightChild());
    }
    else if(z->getRightChild() == this->sentinel)
    {
        x = z->getLeftChild();
        transplant(z, z->getLeftChild());
    }
    else
    {
        RBTNode<key_t, val_t>* min = z->getRightChild();
        
        while(min->getLeftChild() != this->sentinel)
        {
            min = min->getLeftChild();
        }
        
        y = min;
        
        ogY = y->isRed();
        x = y->getRightChild();
        
        if(y->getParent() == z)
        {
            x->setParent(y);
        }
        else
        {
            transplant(y, y->getRightChild());
            y->setRightChild(z->getRightChild());
            y->getRightChild()->setParent(y);
        }
        transplant(z, y);
        y->setLeftChild(z->getLeftChild());
        y->getLeftChild()->setParent(y);
        y->setIsRed(z->isRed());
    }
    
    if(ogY == false)
    {
        deleteFixup(x);
    }
    
    return returnIter2;
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

