
#include <stdio.h>
#include <iostream>
#include "simulate.hpp"
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    
    int numCPU = atoi(argv[1]);
    int numIO = atoi(argv[2]);
    int numCycles = atoi(argv[3]);
    
    ArrayList<Scheduler*>*  arr = new ArrayList<Scheduler*>();
    
    RoundRobin* rr = new RoundRobin();
    FastRoundRobin* frr = new FastRoundRobin();
    CompletelyFair* cf = new CompletelyFair();
    FastCompletelyFair* fcf = new FastCompletelyFair();
    
    //delete these?? ^
    
    arr->pushBack(rr);
    arr->pushBack(frr);
    arr->pushBack(cf);
    arr->pushBack(fcf);
    
    string* sArr = new string[4];
    
    sArr[0] = "Round Robin Data: ";
    sArr[1] = "Fast Round Robin Data: ";
    sArr[2] = "Completely Fair Data: ";
    sArr[3] = "Fast Completely Fair Data: ";


    for(int i = 0; i<arr->getSize(); i++)
    {
        cout<<"--------------------------------------"<<endl;
        double* report = simulate(arr->getItem(i), numCPU, numIO, numCycles);
        
        cout<<sArr[i]<<endl;
        
        cout << "Overhead Caused from Scheduler: " << report[0] <<endl;
        cout << "Average CPU Time: " << report[1] <<endl;
        cout << "Average CPU Wait Time: " << report[2] <<endl;
        cout << "Average IO Time: " << report[3] <<endl;
        cout << "Average IO Wait Time: " << report[4] <<endl;
        
        delete[] report;
    }
    
    delete rr;
    delete frr;
    delete cf;
    delete fcf;
    delete[] sArr;
    delete arr;
    return 0;
    
}





