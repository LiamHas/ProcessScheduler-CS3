

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedList.hpp"
#include <string>

using namespace std;

TEST_CASE("Testing LinkedList Class")
{
    SECTION("Testing LinkedList Class Functions with ints")
    {
        LinkedList<int>* linkList = new LinkedList<int>();
        linkList->pushBack(5);
        linkList->pushBack(3);
        REQUIRE(linkList->getBack() == 3);
        linkList->popBack();
        REQUIRE(linkList->getBack() == 5);

        linkList->pushFront(1);
        REQUIRE(linkList->getFront() == 1);
        linkList->pushFront(2);
        REQUIRE(linkList->getFront() == 2);
        
        linkList->popFront();
        REQUIRE(linkList->getFront() == 1);
        
        linkList->pushFront(9);
        linkList->pushFront(10);

        REQUIRE(linkList->getItem(0) == 10);
        REQUIRE(linkList->getItem(1) == 9);
        REQUIRE(linkList->getItem(2) == 1);
        REQUIRE(linkList->getItem(3) == 5);
        
        linkList->setItem(2, 99);
        linkList->setItem(0, 100);
        linkList->setItem(3, 101);
        REQUIRE(linkList->getItem(2) == 99);
        REQUIRE(linkList->getItem(0) == 100);
        REQUIRE(linkList->getItem(3) == 101);
        
        linkList->insert(0, 62);
        linkList->insert(2, 78);
        linkList->insert(6, 56);

        REQUIRE(linkList->getItem(0) == 62);
        REQUIRE(linkList->getItem(1) == 100);
        REQUIRE(linkList->getItem(2) == 78);
        REQUIRE(linkList->getItem(3) == 9);
        REQUIRE(linkList->getItem(4) == 99);
        REQUIRE(linkList->getItem(5) == 101);
        REQUIRE(linkList->getItem(6) == 56);
        
        linkList->remove(0);
        linkList->remove(3);
        linkList->remove(4);

        REQUIRE(linkList->getItem(0) == 100);
        REQUIRE(linkList->getItem(1) == 78);
        REQUIRE(linkList->getItem(2) == 9);
        REQUIRE(linkList->getItem(3) == 101);
        
        REQUIRE(linkList->getSize() == 4);
        
        linkList->remove(0);
        linkList->remove(0);
        linkList->remove(0);
        linkList->remove(0);
        
        REQUIRE(linkList->isEmpty() == true);
        
        LinkedList<int>* linkList2 = new LinkedList<int>();
        
        linkList2->pushFront(9);
        linkList2->pushFront(9);
        linkList2->pushFront(9);
        linkList2->pushFront(9);
        
        
        linkList2->popBack();
        linkList2->popFront();
        linkList2->setItem(0, 10);

    }
}

