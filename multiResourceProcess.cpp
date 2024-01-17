#include "multiResourceProcess.h"
#include <iostream>

void MultiResourceProcess::initializeProcess(int resources)
{
    std::cout << "Process Id:\t ";
    std::cin >> pid;
    std::cout << "Input the process resources for " << resources << " times" << std::endl;
    for (int i = 0; i < resources; i++)
    {
        int val;
        std::cin >> val;
        process.insert(process.begin() + i, val);
    }
}

MultiResourceProcess::MultiResourceProcess()
{
    ;
}
