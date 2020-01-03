Liam Hasandjekaj
CPS 222 Project 2

Files Submitted: 
catch.hpp 
List.hpp
ArrayList.hpp
ArrayList.tpp
LinkedList.hpp
LinkedList.tpp
LinkedListNode.hpp
LinkedListNode.tpp
BSTMultimap.hpp
BSTMultimap.tpp
BSTNode.hpp
BSTNodetpp
BSTForwardIterator.hpp
BSTForwardIterator.tpp
RBTNode.hpp
RBTNode.tpp
RBTMultimap.hpp
RBTMultimap.tpp
Process.hpp
Process.cpp
Scheduler.hpp
Scheduler.cpp
simulate.hpp
simulate.cpp
schedulesim.cpp
ArrayList_TEST.cpp
LinkedList_TEST.cpp
BSTNode_TEST.cpp
BSTMultimap_TEST.cpp
RBTNode_TEST.cpp
RBTMultimap_TEST.cpp
RoundRobin_TEST.cpp
CompletelyFair_TEST.cpp
Makefile
timing.pdf
cputimes.pdf
readme.txt
Project 2 Final Coversheet - Process Scheduler

This project contains one main program and several related files. Using the command "make all" will compile all files in the project. You can also compile according to the directions below.

---schedulesim---
To compile: make schedulesim
To run: ./schedulesim <number of CPU Bound Processes> <number of IO Bound Processes> <number of process cycles>
Description:

The schedulesim program utilizes different process schedulers to output data on how efficient the schedulers are. The program creates the four different scheduler types and then runs each scheduler through a simulation. The simulation runs using the user given number of CPU bound processes, IO bound processes, and the total number of cycles. The program then prints the data regarding each scheduler's performance to the terminal. When running the program give the <number of CPU Bound Processes>, the <number of IO Bound Processes>, and the total <number of process cycles> for the simulation to perform on each scheduler.



