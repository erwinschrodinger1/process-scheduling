#pragma once
#include <vector>
class MultiResourceProcess
{
public:
    int pid;
    MultiResourceProcess();
    void initializeProcess(int resources);
    std::vector<int> process;

private:
};