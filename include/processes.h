
#include "process.h"
#include <vector>

enum Type
{
    FCFS,
    SJF
};

class Processes
{
public:
    Processes(int size);
    void completionTime(enum Type);

private:
    std::vector<Process>
        processes = {};
    int size;
};
