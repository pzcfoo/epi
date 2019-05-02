#include <iostream>
#include <vector>



void print_vector(std::vector<int> v)
{
    for (auto e: v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


void partition_even_odd(std::vector<int> &a)
{
    int u_s = 0;  // unclassified index start
    int u_e = a.size() - 1;  // unclassified index end
    
    while(u_s != u_e)
    {
        if (a[u_s] % 2)
        {
            auto t = a[u_s];
            a[u_s] = a[u_e];
            a[u_e] = t;
            u_e--;
        }
        else
        {
            u_s++;
        }
    }
}


int main()
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {0};    
    std::vector<int> c = {1, 2};    
    std::vector<int> d = {2, 1};    
    std::vector<int> e = {1, 3, 6, 5, 2, 4};    
    std::vector<std::vector<int>> all = {a, b, c, d, e};
    
    for (auto v: all)
    {
        print_vector(v);
        partition_even_odd(v);
        print_vector(v);
        std::cout << std::endl;
    }
    return 0;
} 



