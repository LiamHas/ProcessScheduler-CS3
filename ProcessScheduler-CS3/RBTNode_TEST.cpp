

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "RBTNode.hpp"
#include <string>
using namespace std;

TEST_CASE("Testing RBTNode Class")
{
    SECTION("Testing RBTNode Class Functions with ints and strings")
    {
        RBTNode<int, string>* n1 = new RBTNode<int, string>(1, "one", true);
        REQUIRE(n1->getKey() == 1);
        REQUIRE(n1->getValue() == "one");
        REQUIRE(n1->getLeftChild() == 0);
        REQUIRE(n1->getRightChild() == 0);
        REQUIRE(n1->getParent() == 0);
        REQUIRE(n1->isRed() == true);
        n1->setIsRed(false);
        REQUIRE(n1->isRed() == false);


        
        RBTNode<int, string>* n2 = new RBTNode<int, string>(2, "two", true);
        RBTNode<int, string>* n3 = new RBTNode<int, string>(3, "three", false);
        RBTNode<int, string>* n4 = new RBTNode<int, string>(4, "four", true);
        RBTNode<int, string>* n5 = new RBTNode<int, string>(5, "five", false);
        RBTNode<int, string>* n6 = new RBTNode<int, string>(6, "six", true);
        RBTNode<int, string>* n7 = new RBTNode<int, string>(7, "seven", false);
        RBTNode<int, string>* n8 = new RBTNode<int, string>(8, "eight", true);
        
        
        n5->setLeftChild(n4);
        n5->setRightChild(n7);
        n4->setLeftChild(n3);
        n3->setLeftChild(n2);
        n7->setRightChild(n8);
        n7->setLeftChild(n6);
        
        REQUIRE(n5->getLeftChild() == n4);
        REQUIRE(n5->getRightChild() == n7);
        REQUIRE(n4->getLeftChild() == n3);
        REQUIRE(n3->getLeftChild() == n2);
        REQUIRE(n7->getRightChild() == n8);
        REQUIRE(n7->getLeftChild() == n6);
        
        n2->setParent(n3);
        n3->setParent(n4);
        n4->setParent(n5);
        n6->setParent(n7);
        n8->setParent(n7);
        n7->setParent(n5);
        
        REQUIRE(n2->getParent() == n3);
        REQUIRE(n3->getParent() == n4);
        REQUIRE(n4->getParent() == n5);
        REQUIRE(n6->getParent() == n7);
        REQUIRE(n8->getParent() == n7);
        REQUIRE(n7->getParent() == n5);
        
       
        
    }
}

