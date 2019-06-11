#include <iostream>
#include <vector>


void print_vec(std::vector<int> &a)
{
    for (auto e: a)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}
