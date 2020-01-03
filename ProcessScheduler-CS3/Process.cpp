#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//Construcor for Process which takes an int and initializes
//member variables to 0
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

//Method that returns the int id value of a Process type
int Process::getID() const
{
   return id;
}

//Method that returns the int cpuTime of a Process type
int Process::getCPUTime() const
{
   return cpuTime;
}

//This method that takes an int as the current cylce number
//It then uses the cycle number and the last time calculated to find
//how much additional time must pass for the process to complete
//It then returns an int that is the total wait time
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

//Constructor that initializes the member lastTime to 0
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

//This function returns false because CPUBoundProcess is never
//blocked and always uses all its given CPU time
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

//This method simulates the time taken for a CPUBoundProcess
//It takes in integers for the currecnt cycle number
//and the slice size. It then updates the cpuTime, waitTime, and lastTime
//variables based on the inputs. It then returns the slice size time
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

//This constructor initializes the members lastTime, blockedUntil
//, and remainingBurst to 0
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

//This function determines if the process is blocked through I/O
//by determining if the current cycle number is less than
//the variable blockedUntil
//It then returns a boolean after evaluating the function
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

//This method simulates and calculates the run time for
//an IOBoundProcess. It takes in the integers for current cycle number
//and slice size. The function accounts for blockage and fringe cases
//and calculates the total time used for the user. It then returns
//the int timeUsed.
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
