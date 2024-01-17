#include <iostream>
#include "process.h"

Process::Process()
{
}

void Process::initializeProcess()
{
    std::cout << "process id: \t";
    std::cin >> pid;
    std::cout << std::endl
              << "process at:\t";
    std::cin >> at;
    std::cout << std::endl
              << "process bt:\t";
    std::cin >> bt;
    std::cout << std::endl;
    return;
}
