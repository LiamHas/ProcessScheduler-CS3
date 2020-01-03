OPTS = -Wall -std=c++11 -g

all: ArrayList_TEST LinkedList_TEST RoundRobin_TEST Scheduler.o Process.o simulate.o schedulesim BSTNode_TEST BSTMultimap_TEST CompletelyFair_TEST RBTNode_TEST RBTMultimap_TEST

ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp List.hpp catch.hpp 
	g++ ${OPTS} -o ArrayList_TEST ArrayList_TEST.cpp

LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedList.tpp LinkedListNode.hpp LinkedListNode.tpp List.hpp catch.hpp 
	g++ ${OPTS} -o LinkedList_TEST LinkedList_TEST.cpp

RoundRobin_TEST: RoundRobin_TEST.cpp Scheduler.o Process.o catch.hpp 
	g++ ${OPTS} -o RoundRobin_TEST RoundRobin_TEST.cpp Scheduler.o Process.o

Scheduler.o: Scheduler.hpp Scheduler.cpp Process.o ArrayList.hpp ArrayList.tpp LinkedList.hpp LinkedList.tpp LinkedListNode.hpp LinkedListNode.tpp List.hpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp BSTForwardIterator.tpp BSTForwardIterator.hpp
	g++ ${OPTS} -c Scheduler.cpp

Process.o: Process.hpp Process.cpp
	g++ ${OPTS} -c Process.cpp

simulate.o: simulate.cpp simulate.hpp Scheduler.o 
	g++ ${OPTS} -c simulate.cpp

schedulesim: schedulesim.cpp Scheduler.o Process.o simulate.o ArrayList_TEST LinkedList_TEST RoundRobin_TEST BSTNode_TEST BSTMultimap_TEST CompletelyFair_TEST RBTNode_TEST RBTMultimap_TEST
	g++ ${OPTS} -o schedulesim schedulesim.cpp Scheduler.o Process.o simulate.o

BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp catch.hpp 
	g++ ${OPTS} -o BSTNode_TEST BSTNode_TEST.cpp

BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.tpp BSTNode.hpp BSTForwardIterator.hpp BSTForwardIterator.tpp catch.hpp 
	g++ ${OPTS} -o BSTMultimap_TEST BSTMultimap_TEST.cpp

CompletelyFair_TEST: CompletelyFair_TEST.cpp Scheduler.o Process.o catch.hpp 
	g++ ${OPTS} -o CompletelyFair_TEST CompletelyFair_TEST.cpp Scheduler.o Process.o

RBTNode_TEST: RBTNode_TEST.cpp BSTNode_TEST RBTNode.hpp RBTNode.tpp catch.hpp 
	g++ ${OPTS} -o RBTNode_TEST RBTNode_TEST.cpp

RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTMultimap.tpp RBTNode.tpp RBTNode.hpp BSTMultimap.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp catch.hpp 
	g++ ${OPTS} -o RBTMultimap_TEST RBTMultimap_TEST.cpp







