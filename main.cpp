#include <iostream>
#include "processes.h"
#include <vector>
#include "process.h"
#include "multiResourceProcesses.h"

int main()
{
    int size;
    std::cout << "Input the number of multi resource processes" << std::endl;
    std::cin >> size;
    int resources;
    std::cout << "Input the number of resources" << std::endl;
    std::cin >> resources;
    MultiResourceProcesses multiProcesses(size, resources);
    multiProcesses.bankers();
    std::cout << "Inputing normal processes.." << std::endl;
    Processes processes(size);
    std::cout << "FCFS Output:" << std::endl;
    processes.completionTime(FCFS);
    std::cout << "SJF Output:" << std::endl;
    processes.completionTime(SJF);
    return 0;
}
