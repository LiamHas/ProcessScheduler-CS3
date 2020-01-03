

#include <stdio.h>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Scheduler.hpp"

TEST_CASE("Testing CompletelyFair Class")
{
    SECTION("Testing CompletelyFair Class Functions")
    {
        CompletelyFair* cf = new CompletelyFair();
        
        CPUBoundProcess* cpu1 = new CPUBoundProcess(1);
        CPUBoundProcess* cpu2 = new CPUBoundProcess(2);
        CPUBoundProcess* cpu3 = new CPUBoundProcess(3);
        
        cf->addProcess(cpu1);
        cf->addProcess(cpu2);
        cf->addProcess(cpu3);
        
        REQUIRE(cf->popNext(0)->getID() == 1);
        
        CompletelyFair* cf2 = new CompletelyFair();
        
        IOBoundProcess* cpu4 = new IOBoundProcess(10);
        IOBoundProcess* cpu5 = new IOBoundProcess(11);
        IOBoundProcess* cpu6 = new IOBoundProcess(12);
        
        cf2->addProcess(cpu4);
        cf2->addProcess(cpu5);
        cf2->addProcess(cpu6);
        
        int i = 0;
        while(!cpu4->isBlocked(i))
        {
            cpu4->useCPU(i, i);
            i++;
        }
        
        REQUIRE(cf2->popNext(i)->getID() == 11);
        
        int j = 0;
        while(!cpu5->isBlocked(j))
        {
            cpu5->useCPU(j, j);
            j++;
        }
        
        REQUIRE(cf2->popNext(j)->getID() == 12);
        
        int k = 0;
        while(!cpu6->isBlocked(k))
        {
            cpu6->useCPU(k, k);
            k++;
        }
    }
    
}
