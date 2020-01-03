

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Scheduler.hpp"

TEST_CASE("Testing RoundRobin Class")
{
    SECTION("Testing RoundRobin Class Functions with ints")
    {
        RoundRobin* rr = new RoundRobin();
        
        CPUBoundProcess* cpu1 = new CPUBoundProcess(1);
        CPUBoundProcess* cpu2 = new CPUBoundProcess(2);
        CPUBoundProcess* cpu3 = new CPUBoundProcess(3);

        rr->addProcess(cpu1);
        rr->addProcess(cpu2);
        rr->addProcess(cpu3);

        REQUIRE(rr->popNext(0)->getID() == 1);
        
        RoundRobin* rr2 = new RoundRobin();
        
        IOBoundProcess* cpu4 = new IOBoundProcess(10);
        IOBoundProcess* cpu5 = new IOBoundProcess(11);
        IOBoundProcess* cpu6 = new IOBoundProcess(12);

        rr2->addProcess(cpu4);
        rr2->addProcess(cpu5);
        rr2->addProcess(cpu6);
        
        int i = 0;
        while(!cpu4->isBlocked(i))
        {
            cpu4->useCPU(i, i);
            i++;
        }
        
        REQUIRE(rr2->popNext(i)->getID() == 11);
        
        int j = 0;
        while(!cpu5->isBlocked(j))
        {
            cpu5->useCPU(j, j);
            j++;
        }

        REQUIRE(rr2->popNext(j)->getID() == 12);

        int k = 0;
        while(!cpu6->isBlocked(k))
        {
            cpu6->useCPU(k, k);
            k++;
        }
        
        REQUIRE(rr2->popNext(k) == 0);

    }
    
    SECTION("Testing FastRoundRobin Class Functions with ints")
    {
        FastRoundRobin* rr = new FastRoundRobin();
        
        CPUBoundProcess* cpu1 = new CPUBoundProcess(1);
        CPUBoundProcess* cpu2 = new CPUBoundProcess(2);
        CPUBoundProcess* cpu3 = new CPUBoundProcess(3);
        
        rr->addProcess(cpu1);
        rr->addProcess(cpu2);
        rr->addProcess(cpu3);
        
        REQUIRE(rr->popNext(0)->getID() == 1);
        
        RoundRobin* rr2 = new RoundRobin();
        
        IOBoundProcess* cpu4 = new IOBoundProcess(10);
        IOBoundProcess* cpu5 = new IOBoundProcess(11);
        IOBoundProcess* cpu6 = new IOBoundProcess(12);
        
        rr2->addProcess(cpu4);
        rr2->addProcess(cpu5);
        rr2->addProcess(cpu6);
        
        int i = 0;
        while(!cpu4->isBlocked(i))
        {
            cpu4->useCPU(i, i);
            i++;
        }
        
        REQUIRE(rr2->popNext(i)->getID() == 11);
        
        int j = 0;
        while(!cpu5->isBlocked(j))
        {
            cpu5->useCPU(j, j);
            j++;
        }
        
        REQUIRE(rr2->popNext(j)->getID() == 12);
        
        int k = 0;
        while(!cpu6->isBlocked(k))
        {
            cpu6->useCPU(k, k);
            k++;
        }
        
        REQUIRE(rr2->popNext(k) == 0);
        
    }
}
