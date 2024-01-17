#include <vector>
enum Operation
{
    SUM,
    DIFF
};
std::vector<int> vectorOperation(enum Operation, const std::vector<int> &vec1, const std::vector<int> &vec2);
int vectorCompare(const std::vector<int> &vec1, const std::vector<int> &vec2);