

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "BSTNode.hpp"
#include <string>
using namespace std;

TEST_CASE("Testing BSTNode Class")
{
    SECTION("Testing BSTNode Class Functions with ints and strings")
    {
        BSTNode<int, string>* n1 = new BSTNode<int, string>(1, "one");
        REQUIRE(n1->getKey() == 1);
        REQUIRE(n1->getValue() == "one");
        REQUIRE(n1->getLeftChild() == 0);
        REQUIRE(n1->getRightChild() == 0);
        REQUIRE(n1->getParent() == 0);
        
        BSTNode<int, string>* n2 = new BSTNode<int, string>(2, "two");
        BSTNode<int, string>* n3 = new BSTNode<int, string>(3, "three");
        BSTNode<int, string>* n4 = new BSTNode<int, string>(4, "four");
        BSTNode<int, string>* n5 = new BSTNode<int, string>(5, "five");
        BSTNode<int, string>* n6 = new BSTNode<int, string>(6, "six");
        BSTNode<int, string>* n7 = new BSTNode<int, string>(7, "seven");
        BSTNode<int, string>* n8 = new BSTNode<int, string>(8, "eight");

        
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

        n7->setKey(10);
        n7->setValue("0");

    }
}

