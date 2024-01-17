#include "processes.h"
#include "iostream"
#include "process.h"
#include <algorithm>

bool fcfsSort(Process &a, Process &b)
{
    return a.at < b.at;
}
bool sjfSort(Process &a, Process &b)
{
    return a.at <= b.at && a.bt < b.bt;
}

Processes::Processes(int size) : size(size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << i << std::endl;
        Process process;
        process.initializeProcess();
        processes.insert(processes.end(), process);
    }
}

void Processes::completionTime(Type type)
{
    switch (type)
    {
    case FCFS:
        std::sort(processes.begin(), processes.end(), fcfsSort);
        break;

    case SJF:
        std::sort(processes.begin(), processes.end(), sjfSort);
        break;
    }
    int ct = 0;
    int at = 0;
    for (int i = 0; i < processes.size(); i++)
    {
        ct = processes.at(i).bt + ct + (processes.at(i).at > at ? processes.at(i).at - at : 0);
        at = ct;
        std::cout << "Process id: " << processes.at(i).pid << "| Process at: " << processes.at(i).at << "| Process bt: " << processes.at(i).bt << " | Process ct: " << ct << " | Process tt: " << ct - processes.at(i).at << std::endl;
    }
}
