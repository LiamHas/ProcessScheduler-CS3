
#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTMultimap.hpp"
#include "BSTForwardIterator.hpp"
#include <string>
using namespace std;

TEST_CASE("Testing BSTMultimap Class")
{
    SECTION("Testing BSTMultimap Class Functions with ints and numerics")
    {
        BSTMultimap<int, int>* bstm = new BSTMultimap<int, int>();
        
        REQUIRE(bstm->getSize() == 0);
        REQUIRE(bstm->isEmpty() == true);
        
        bstm->insert(2, 2);
        bstm->insert(3, 3);
        bstm->insert(1, 1);
        
        REQUIRE(bstm->getSize() == 3);
        REQUIRE(bstm->isEmpty() == false);
        
        REQUIRE(bstm->contains(2) == true);
        REQUIRE(bstm->contains(3) == true);
        REQUIRE(bstm->contains(1) == true);
        
        REQUIRE(bstm->contains(0) == false);
        REQUIRE(bstm->contains(4) == false);

        BSTForwardIterator<int,int> smlTree = bstm->getMin();
        REQUIRE(smlTree.getValue() == 1);
        
        BSTForwardIterator<int,int> c = bstm->getMax();
        REQUIRE(c.getKey() == 3);
        
     //   cout<<bstm->toString()<<endl;

        BSTMultimap<float, int>* bstm2 = new BSTMultimap<float, int>();

        bstm2->insert(5.0, 5);
        bstm2->insert(4.0, 4);
        bstm2->insert(3.0, 3);
        bstm2->insert(2.0, 2);
        bstm2->insert(7.0, 7);
        bstm2->insert(6.0, 6);
        bstm2->insert(8.0, 8);
        
        REQUIRE(bstm2->getSize() == 7);
        REQUIRE(bstm2->isEmpty() == false);

     //   cout<<bstm2->toString()<<endl;
        
        REQUIRE(bstm2->contains(5.0) == true);
        REQUIRE(bstm2->contains(4.0) == true);
        REQUIRE(bstm2->contains(3.0) == true);
        REQUIRE(bstm2->contains(2.0) == true);
        REQUIRE(bstm2->contains(7.0) == true);
        REQUIRE(bstm2->contains(6.0) == true);
        REQUIRE(bstm2->contains(8.0) == true);
        
        REQUIRE(bstm2->contains(5.1) == false);
        REQUIRE(bstm2->contains(1.0) == false);
        REQUIRE(bstm2->contains(0) == false);
        REQUIRE(bstm2->contains(10) == false);
        REQUIRE(bstm2->contains(2.5) == false);
        REQUIRE(bstm2->contains(6.9) == false);

     //   cout<<bstm2->toString()<<endl;

        BSTForwardIterator<float,int> bgTree = bstm2->getMin();
        REQUIRE(bgTree.getValue() == 2);
        
        BSTForwardIterator<float,int> d = bstm2->getMax();
        REQUIRE(d.getKey() == 8);
    
        bstm2->clear();
        REQUIRE(bstm2->getSize() == 0);
        
        REQUIRE(bstm2->contains(5.0) == false);
        REQUIRE(bstm2->contains(4.0) == false);
        REQUIRE(bstm2->contains(3.0) == false);
        REQUIRE(bstm2->contains(2.0) == false);
        REQUIRE(bstm2->contains(7.0) == false);
        REQUIRE(bstm2->contains(6.0) == false);
        REQUIRE(bstm2->contains(8.0) == false);
    }
    SECTION("Testing BSTMultimap with Iterator implementation")
    {
        BSTMultimap<int, int>* bstm3 = new BSTMultimap<int, int>();

        bstm3->insert(7, 7);
        bstm3->insert(4, 4);
        bstm3->insert(2, 2);
        bstm3->insert(3, 3);
        bstm3->insert(6, 6);
        bstm3->insert(5, 5);
        bstm3->insert(12, 12);
        bstm3->insert(9, 9);
        bstm3->insert(19, 19);
        bstm3->insert(8, 8);
        bstm3->insert(11, 11);
        bstm3->insert(15, 15);
        bstm3->insert(20, 20);

       // cout<<bstm3->toString()<<endl;
        
        BSTForwardIterator<int,int> a = bstm3->getMin();
        
        REQUIRE(a.getKey() == 2);
        REQUIRE(a.getValue() == 2);
        
        a.next();
        REQUIRE(a.getValue() == 3);
        a.next();
        REQUIRE(a.getValue() == 4);
        a.next();
        REQUIRE(a.getValue() == 5);
        a.next();
        REQUIRE(a.getValue() == 6);
        a.next();
        REQUIRE(a.getValue() == 7);
        a.next();
        REQUIRE(a.getValue() == 8);
        a.next();
        REQUIRE(a.getValue() == 9);
        a.next();
        REQUIRE(a.getValue() == 11);
        a.next();
        REQUIRE(a.getValue() == 12);
        a.next();
        REQUIRE(a.getValue() == 15);
        a.next();
        REQUIRE(a.getValue() == 19);
        a.next();
        REQUIRE(a.getValue() == 20);

        REQUIRE(a.isPastEnd() == false);
        a.next();
        REQUIRE(a.isPastEnd() == true);
        
        BSTForwardIterator<int,int> b = bstm3->getMax();
        REQUIRE(b.getKey() == 20);
    }
    
    SECTION("Testing BSTMultimap with findFirst and findLast")
    {
        BSTMultimap<int, int>* bstm4 = new BSTMultimap<int, int>();
        bstm4->insert(5, 3);
        bstm4->insert(3, 1);
        bstm4->insert(7, 5);
        bstm4->insert(5, 2);
        bstm4->insert(5, 4);
        
       // cout<<bstm4->toString()<<endl;
        BSTForwardIterator<int,int> itr = bstm4->findFirst(5);
        REQUIRE(itr.getValue() == 3);
        
        BSTForwardIterator<int,int> itr2 = bstm4->findLast(5);
        REQUIRE(itr2.getValue() == 4);
        
        bstm4->insert(4, 1);
        bstm4->insert(4, 20);
        
        BSTForwardIterator<int,int> itr3 = bstm4->findFirst(4);
        REQUIRE(itr3.getValue() == 1);
        
        BSTForwardIterator<int,int> itr4 = bstm4->findLast(4);
        REQUIRE(itr4.getValue() == 20);

    }
    SECTION("Testing remove")
    {
        BSTMultimap<int, int>* bstm5 = new BSTMultimap<int, int>();
        bstm5->insert(8, 8);
        bstm5->insert(7, 7);
        bstm5->insert(12, 12);
        bstm5->insert(5, 5);
        bstm5->insert(6, 6);
        bstm5->insert(9, 9);
        bstm5->insert(13, 13);
        bstm5->insert(10, 10);
        
        BSTForwardIterator<int,int> b = bstm5->getMin();
        
       // cout<<bstm5->toString()<<endl;
        
        bstm5->remove(b);
       // cout<<bstm5->toString()<<endl;
        REQUIRE(bstm5->contains(5) == false);
        
        b.next();
        b.next();
        b.next();
        b.next();
        b.next();
        b.next();
        
        bstm5->remove(b);
       // cout<<bstm5->toString()<<endl;
        REQUIRE(bstm5->contains(12) == false);
        
        BSTForwardIterator<int,int> c = bstm5->getMin();
        c.next();
        c.next();
      //  cout<<c.getKey()<<endl;
        bstm5->remove(c);
      //  cout<<bstm5->toString()<<endl;
        REQUIRE(bstm5->contains(8) == false);
        
        b.next();
        bstm5->remove(b);
      //  cout<<bstm5->toString()<<endl;
        REQUIRE(bstm5->contains(10) == false);

    }
    
    SECTION("Testing remove")
    {
        BSTMultimap<int, int>* bstm5 = new BSTMultimap<int, int>();
        bstm5->insert(8, 8);
        bstm5->insert(7, 7);
        
        BSTForwardIterator<int,int> bstm6 = bstm5->getMin();
        bstm5->remove(bstm6);
        
        
        BSTMultimap<int, int>* bstm7 = new BSTMultimap<int, int>();
        bstm7->getMin();
        delete bstm7;
    }
}
