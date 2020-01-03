
#ifndef simulate_hpp
#define simulate_hpp

#include <stdio.h>
#include "Scheduler.hpp"

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles);

#endif /* simulate_hpp */
