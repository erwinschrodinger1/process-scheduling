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
    std::vector<int> available = totalResources.process;
    std::vector<MultiResourceProcess> duplicate = processes;
    int tempSize = size;
    int completedProcess = 0;
    std::cout << "Executing Processes.." << std::endl;
    while (completedProcess != processes.size())
    {
        bool isProcessExecuted = 0;
        for (int i = 0; i < tempSize; i++)
        {
            std::cout << "Process of PID: " << duplicate.at(i).pid << "\nneed: \t";
            printVector(duplicate.at(i).process);
            std::cout << "Available: \t";
            printVector(available);
            if (vectorCompare(duplicate.at(i).process, available) == -1)
            {
                available = vectorOperation(SUM, available, duplicate.at(i).process);
                std::cout
                    << "Executing Process of Process id: " << duplicate.at(i).pid << std::endl;
                duplicate.erase(duplicate.begin() + i);
                tempSize -= 1;
                i -= 1;
                completedProcess++;
                isProcessExecuted = 1;
            }
        }
        if (!isProcessExecuted && completedProcess != size)
        {
            std::cout << "Invalid Cannot proceed" << std::endl;
            return;
        }
    }
}
