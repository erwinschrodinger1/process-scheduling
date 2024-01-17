#include "multiResourceProcess.h"
#include <vector>

class MultiResourceProcesses
{
public:
    MultiResourceProcesses(int size, int resources);
    void bankers();

private:
    std::vector<MultiResourceProcess>
        processes = {};
    int size;
    int resources;
    MultiResourceProcess totalResources;
};
