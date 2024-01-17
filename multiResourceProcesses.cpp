#include "multiResourceProcesses.h"
#include <iostream>
#include "vectorOperation.h"
#include <algorithm>

MultiResourceProcesses::MultiResourceProcesses(int size, int resources) : resources(resources), size(size)
{
    std::cout << "Total Process resources: " << std::endl;
    totalResources.initializeProcess(resources);
    for (int i = 0; i < size; i++)
    {
        MultiResourceProcess process;
        process.initializeProcess(resources);
        processes.insert(processes.end(), process);
    }
}

bool multiResourceSort(MultiResourceProcess &a, MultiResourceProcess &b)
{
    return vectorCompare(a.process, b.process) == -1;
}

void MultiResourceProcesses::bankers()
{
    std::vector<int> used = processes.at(0).process;
    for (int i = 1; i < size - 1; i++)
    {
        used = vectorOperation(SUM, used, processes.at(i).process);
    }
    std::vector<int> available = vectorOperation(DIFF, totalResources.process, used);
    std::sort(processes.begin(), processes.end(), multiResourceSort);
    int completedProcess = 0;
    for (int i = 0; i < size; i++)
    {
        if (vectorCompare(processes.at(i).process, available) == -1)
        {
            std::cout << "Process id: " << processes.at(i).pid << std::endl;
            completedProcess++;
        }
    }
    if (completedProcess != processes.size())
    {
        std::cout << "Invalid Cannot proceed" << std::endl;
    }
}
