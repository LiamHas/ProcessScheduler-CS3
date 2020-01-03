
#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ArrayList.hpp"
#include <string>

using namespace std;

TEST_CASE("Testing ArrayList Class")
{
    SECTION("Testing ArrayList Class Functions with ints")
    {
        ArrayList<int> *a = new ArrayList<int>();
        REQUIRE(a->getCapacity() == 10);
        REQUIRE(a->getSize() == 0);
        
        ArrayList<double> *b = new ArrayList<double>(31);
        REQUIRE(b->getCapacity() == 31);
        REQUIRE(b->getSize() == 0);
        REQUIRE(b->isEmpty() == true);
        
        a->pushFront(25);
        a->pushFront(5);
        a->pushFront(17);

        REQUIRE(a->isEmpty() == false);

        REQUIRE(a->getSize() == 3);
        REQUIRE(a->getBack() == 25);
        REQUIRE(a->getFront() == 17);
    
        REQUIRE(a->getItem(0) == 17);
        REQUIRE(a->getItem(1) == 5);
        REQUIRE(a->getItem(2) == 25);
        
        a->pushBack(42);
        REQUIRE(a->getBack() == 42);
        a->popBack();
        REQUIRE(a->getBack() == 25);

        
        a->insert(1, 11);
        a->insert(2, 99);

        REQUIRE(a->getItem(1) == 11);
        REQUIRE(a->getItem(2) == 99);
        REQUIRE(a->getItem(3) == 5);
        REQUIRE(a->getSize() == 5);
        
        a->setItem(1, 13);
        REQUIRE(a->getItem(1) == 13);
        
        a->popFront();
        REQUIRE(a->getFront() == 13);

        a->remove(1);
        
        REQUIRE(a->getItem(1) == 5);
        REQUIRE(a->getSize() == 3);
   
    }
    SECTION("Testing ArrayList Class Functions with strings")
    {
        ArrayList<string> *a = new ArrayList<string>();
        REQUIRE(a->getCapacity() == 10);
        REQUIRE(a->getSize() == 0);
        
        ArrayList<char> *b = new ArrayList<char>(9);
        REQUIRE(b->getCapacity() == 9);
        REQUIRE(b->getSize() == 0);
        REQUIRE(b->isEmpty() == true);
        
        a->pushFront("25");
        a->pushFront("5");
        a->pushFront("17");
        
        REQUIRE(a->isEmpty() == false);
        
        REQUIRE(a->getSize() == 3);
        REQUIRE(a->getBack() == "25");
        REQUIRE(a->getFront() == "17");
        
        REQUIRE(a->getItem(0) == "17");
        REQUIRE(a->getItem(1) == "5");
        REQUIRE(a->getItem(2) == "25");
        
        a->pushBack("42");
        REQUIRE(a->getBack() == "42");
        
        a->popBack();
        REQUIRE(a->getBack() == "25");
        
        a->insert(1, "11");
        a->insert(2, "99");
        
        REQUIRE(a->getItem(1) == "11");
        REQUIRE(a->getItem(2) == "99");
        REQUIRE(a->getItem(3) == "5");
        REQUIRE(a->getSize() == 5);
        
        a->setItem(1, "13");
        REQUIRE(a->getItem(1) == "13");
        
        a->popFront();
        REQUIRE(a->getFront() == "13");
        
        a->remove(1);
        
        REQUIRE(a->getItem(1) == "5");
        REQUIRE(a->getSize() == 3);
    }
    
    SECTION("Testing Fringe Cases")
    {
        ArrayList<int> *a = new ArrayList<int>();
        for(int i = 0; i<15; i++)
        {
            a->pushBack(25);
        }
        
        ArrayList<int> *b = new ArrayList<int>();
        for(int i = 0; i<15; i++)
        {
            b->pushFront(25);
        }
        
        ArrayList<int> *c = new ArrayList<int>();
        for(int i = 0; i<15; i++)
        {
            c->insert(i+1, 10);
        }
        
        c->insert(0, 10);
        c->remove(0);
        c->remove(c->getSize()-1);
    }
    
}


