
#include <stdio.h>
#include "simulate.hpp"
#include <chrono>

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles)
{
    ArrayList<Process*>* tracker = new ArrayList<Process*>();

    for(int i = 0; i < numCPUBound; i++)
    {
        CPUBoundProcess* b = new CPUBoundProcess(i);
        Process* track = b;
        sched->addProcess(b);
        tracker->pushBack(track);
    }
    for(int i = 0; i < numIOBound; i++)
    {
        IOBoundProcess* c = new IOBoundProcess(i);
        Process* track = c;
        sched->addProcess(c);
        tracker->pushBack(track);
    }
    
    auto t1 = chrono::system_clock::now();
    
    int j = 0;
    int curCycle = 0;

    
    while(curCycle <= numCycles)
    {
        Process* a = sched->popNext(curCycle);
        
        if(a == 0)
        {
            curCycle += 10;
        }
        else
        {
            j++;
            int cyclesUsed = a->useCPU(curCycle, 10);
            curCycle += cyclesUsed;
            sched->addProcess(a);
        }
    }

    auto t2 = chrono::system_clock::now();
    auto dur = t2 - t1;
    auto durNS = chrono::duration_cast<chrono::nanoseconds>(dur);
    
    double totalCPUTime = 0;
    double totalCPUWaitTime = 0;
    for(int i = 0; i < numCPUBound; i++)
    {
        totalCPUTime += tracker->getItem(i)->getCPUTime();
        totalCPUWaitTime += tracker->getItem(i)->getWaitTime(curCycle);
    }
    
    double totalIOTime = 0;
    double totalIOWaitTime = 0;

    for(int i = numCPUBound; i < numIOBound+numCPUBound; i++)
    {
        if(tracker->getItem(i) != 0)
        {
            totalIOTime += tracker->getItem(i)->getCPUTime();
            totalIOWaitTime += tracker->getItem(i)->getWaitTime(curCycle);
        }

    }
    
    double* report = new double[5];
    report[0] = double(durNS.count()) / j;
    report[1] = double(totalCPUTime)/numCPUBound;
    report[2] = double(totalCPUWaitTime)/numCPUBound;
    report[3] = double(totalIOTime)/numIOBound;
    report[4] = double(totalIOWaitTime)/numIOBound;
    
    delete tracker;

    return report;


}













