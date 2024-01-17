#include "vectorOperation.h"
#include <iostream>

std::vector<int> vectorOperation(Operation operation, const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        std::cout << "Error: Vectors must have the same size to add them." << std::endl;
        return std::vector<int>();
    }

    std::vector<int> result(vec1.size());

    for (int i = 0; i < vec1.size(); i++)
    {
        switch (operation)
        {
        case SUM:
            result[i] = vec1[i] + vec2[i];
            break;

        case DIFF:
            result[i] = vec1[i] - vec2[i];
            break;
        }
    }

    return result;
}

/// @brief compares each element of two vectors
/// @param vec1
/// @param vec2
/// @return -1 if less
///          0 if equal
///          1 if greater
///         -2 if invalid
int vectorCompare(const std::vector<int> &vec1, const std::vector<int> &vec2)
{
    if (vec1.size() != vec2.size())
    {
        std::cout << "Error: Vectors must have the same size to add them." << std::endl;
        return -2;
    }
    int flag = (vec1[0] <= vec2[0]) ? -1 : (vec1[0] == vec2[0]) ? 0
                                                                : 1;
    for (int i = 1; i < vec1.size(); i++)
    {
        int newFlag = (vec1[i] <= vec2[i]) ? -1 : (vec1[i] == vec2[i]) ? 0
                                                                       : 1;
        if (flag != newFlag)
        {
            return -2;
        }
    }
    return 0;
}
