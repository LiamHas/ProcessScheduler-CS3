
#include <stdio.h>
#include <iostream>
#include "Scheduler.hpp"

using namespace std;

RoundRobin::RoundRobin()
{
    procQueue = new ArrayList<Process*>();
}

RoundRobin::~RoundRobin()
{
    delete procQueue;
}

void RoundRobin::addProcess(Process* proc)
{
    procQueue->pushBack(proc);
}

Process* RoundRobin::popNext(int curCycle)
{
    if(procQueue->isEmpty())
    {
        return 0;
    }
    int j = 0;
    while(j != procQueue->getSize())
    {
        j++;
        if(procQueue->getFront()->isBlocked(curCycle))
        {
            procQueue->pushBack(procQueue->getFront());
            procQueue->popFront();
        }
        else
        {
            Process* a = procQueue->getFront();
            procQueue->popFront();
            return a;
        }
        
    }
    return 0;
}

FastRoundRobin::FastRoundRobin()
{
    delete procQueue;

    procQueue = new LinkedList<Process*>();
}

CompletelyFair::CompletelyFair()
{
    procTree = new BSTMultimap<int, Process*>();
}
CompletelyFair::~CompletelyFair()
{
    delete procTree;
}
void CompletelyFair::addProcess(Process* proc)
{
    procTree->insert(proc->getCPUTime(), proc);
}
Process* CompletelyFair::popNext(int curCycle)
{
    BSTForwardIterator<int, Process*> iter = procTree->getMin();
    
    int j = 0;
    
    while(iter.getValue()->isBlocked(curCycle))
    {
        j++;
        if(j == procTree->getSize())
        {
            return 0;
        }
        iter.next();
    }

    Process* iterCopy = iter.getValue();

    procTree->remove(iter);
    
    return iterCopy;
}


FastCompletelyFair::FastCompletelyFair()
{
    delete procTree;
    procTree = new RBTMultimap<int, Process*>();
    
}
