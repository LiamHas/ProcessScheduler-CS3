
#ifndef Scheduler_hpp
#define Scheduler_hpp

#include <stdio.h>
#include "Process.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "BSTMultimap.hpp"
#include "RBTMultimap.hpp"


class Scheduler
{
    public:
        virtual void addProcess(Process* proc) = 0;
        virtual Process* popNext(int curCycle) = 0;
        virtual ~Scheduler(){}
};

class RoundRobin : public Scheduler
{
    protected:
        List<Process*>* procQueue;
    public:
        RoundRobin();
        virtual ~RoundRobin();
        virtual void addProcess(Process* proc);
        virtual Process* popNext(int curCycle);
};

class FastRoundRobin : public RoundRobin
{
    public:
        FastRoundRobin();
};

class CompletelyFair : public Scheduler
{
    protected:
        BSTMultimap<int, Process*>* procTree;
    public:
        CompletelyFair();
        virtual ~CompletelyFair();
        virtual void addProcess(Process* proc);
        virtual Process* popNext(int curCycle);
    
};

class FastCompletelyFair : public CompletelyFair
{
    public:
        FastCompletelyFair();
};
#endif /* Scheduler_hpp */
