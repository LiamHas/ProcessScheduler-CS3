

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "RBTMultimap.hpp"
#include "BSTForwardIterator.hpp"
#include <string>
using namespace std;

TEST_CASE("Testing RBTMultimap Class")
{
    SECTION("Testing RBTMultimap Class Functions")
    {
        RBTMultimap<int, int>* rbtm = new RBTMultimap<int, int>();
        
        REQUIRE(rbtm->getSize() == 0);
        REQUIRE(rbtm->isEmpty() == true);
        
        rbtm->insert(2, 2);
        rbtm->insert(3, 3);
        rbtm->insert(1, 1);
        
       // rbtm->printDOT("rbtm.dot");

        REQUIRE(rbtm->getSize() == 3);
        REQUIRE(rbtm->isEmpty() == false);
        
        REQUIRE(rbtm->contains(2) == true);
        REQUIRE(rbtm->contains(3) == true);
        REQUIRE(rbtm->contains(1) == true);
        
        REQUIRE(rbtm->contains(0) == false);
        REQUIRE(rbtm->contains(4) == false);
        
        BSTForwardIterator<int,int> c = rbtm->getMax();
        REQUIRE(c.getKey() == 3);
        
        //   cout<<bstm->toString()<<endl;
        
        RBTMultimap<float, int>* rbtm2 = new RBTMultimap<float, int>();
        
        rbtm2->insert(5.0, 5);
        rbtm2->insert(4.0, 4);
        rbtm2->insert(3.0, 3);
        rbtm2->insert(2.0, 2);
        rbtm2->insert(7.0, 7);
        rbtm2->insert(6.0, 6);
        rbtm2->insert(8.0, 8);
        
        REQUIRE(rbtm2->getSize() == 7);
        REQUIRE(rbtm2->isEmpty() == false);
        
        //   cout<<bstm2->toString()<<endl;
        
        REQUIRE(rbtm2->contains(5.0) == true);
        REQUIRE(rbtm2->contains(4.0) == true);
        REQUIRE(rbtm2->contains(3.0) == true);
        REQUIRE(rbtm2->contains(2.0) == true);
        REQUIRE(rbtm2->contains(7.0) == true);
        REQUIRE(rbtm2->contains(6.0) == true);
        REQUIRE(rbtm2->contains(8.0) == true);
        
        REQUIRE(rbtm2->contains(5.1) == false);
        REQUIRE(rbtm2->contains(1.0) == false);
        REQUIRE(rbtm2->contains(0) == false);
        REQUIRE(rbtm2->contains(10) == false);
        REQUIRE(rbtm2->contains(2.5) == false);
        REQUIRE(rbtm2->contains(6.9) == false);
        
        //   cout<<bstm2->toString()<<endl;
        
        BSTForwardIterator<float,int> bgTree = rbtm2->getMin();
        REQUIRE(bgTree.getValue() == 2);
        
        BSTForwardIterator<float,int> d = rbtm2->getMax();
        REQUIRE(d.getKey() == 8);
        
        rbtm2->clear();
        REQUIRE(rbtm2->getSize() == 0);
        
        REQUIRE(rbtm2->contains(5.0) == false);
        REQUIRE(rbtm2->contains(4.0) == false);
        REQUIRE(rbtm2->contains(3.0) == false);
        REQUIRE(rbtm2->contains(2.0) == false);
        REQUIRE(rbtm2->contains(7.0) == false);
        REQUIRE(rbtm2->contains(6.0) == false);
        REQUIRE(rbtm2->contains(8.0) == false);
        
    }
    SECTION("Testing RBTMultimap insert and remove")
    {
        RBTMultimap<int, int>* rbtm3 = new RBTMultimap<int, int>();
        
        rbtm3->insert(5, 5);
        
        rbtm3->insert(3, 3);

        rbtm3->insert(11, 11);
        
        rbtm3->insert(2, 2);

        rbtm3->insert(8, 8);

        rbtm3->insert(14, 14);

        rbtm3->insert(9, 9);

        rbtm3->insert(7, 7);

        rbtm3->insert(6, 6);

      //  cout<<rbtm3->toString()<<endl;
        rbtm3->printDOT("rbtm3.dot");
        
        
        BSTForwardIterator<int,int> rbtm3Min = rbtm3->getMin();
        BSTForwardIterator<int,int> rbtm3Max = rbtm3->getMax();

        REQUIRE(rbtm3Min.getValue() == 2);
        REQUIRE(rbtm3Max.getValue() == 14);
        
        rbtm3Min.next();
        REQUIRE(rbtm3Min.getKey() == 3);
        
        rbtm3->remove(rbtm3Min);
        
      //  cout<<rbtm3->toString()<<endl;
        
        rbtm3Min.next();
        rbtm3Min.next();
        rbtm3Min.next();
        rbtm3Min.next();


        REQUIRE(rbtm3Min.getKey() == 8);
        
        rbtm3->remove(rbtm3Min);

      ///  cout<<rbtm3->toString()<<endl;
        
        BSTForwardIterator<int,int> rbtm3Min2 = rbtm3->getMin();
        REQUIRE(rbtm3Min2.getKey() == 2);
        
        rbtm3->remove(rbtm3Min2);

     //   cout<<rbtm3->toString()<<endl;

        rbtm3Min2.next();
        rbtm3Min2.next();
        rbtm3Min2.next();
        rbtm3Min2.next();
        rbtm3Min2.next();

        rbtm3->remove(rbtm3Min2);
      //  cout<<rbtm3->toString()<<endl;
        
        rbtm3Min2.next();
        
        rbtm3->remove(rbtm3Min2);
     //   cout<<rbtm3->toString()<<endl;

        BSTForwardIterator<int,int> rbtm3Max2 = rbtm3->getMax();
        REQUIRE(rbtm3Max2.getKey() == 9);

        rbtm3->remove(rbtm3Max2);
       // cout<<rbtm3->toString()<<endl;

    }
    SECTION("Testing RBTMultimap findFirst and findLast")
    {
        BSTMultimap<int, int>* rbtm4 = new RBTMultimap<int, int>();
        rbtm4->insert(5, 3);
        rbtm4->insert(3, 1);
        rbtm4->insert(7, 5);
        rbtm4->insert(5, 2);
        rbtm4->insert(5, 4);
        
        //cout<<rbtm4->toString()<<endl;
        BSTForwardIterator<int,int> itr = rbtm4->findFirst(5);
        REQUIRE(itr.getValue() == 3);
        
        BSTForwardIterator<int,int> itr2 = rbtm4->findLast(5);
        REQUIRE(itr2.getValue() == 4);
        
        rbtm4->insert(4, 1);
        rbtm4->insert(4, 20);
        
        BSTForwardIterator<int,int> itr3 = rbtm4->findFirst(4);
        REQUIRE(itr3.getValue() == 1);
        
        BSTForwardIterator<int,int> itr4 = rbtm4->findLast(4);
        REQUIRE(itr4.getValue() == 20);
        
        delete rbtm4;
        
    }
}
