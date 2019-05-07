#include <iostream>
#include <vector>
using std::vector;
typedef enum { kRed, kWhite, kBlue } Color;

void _dutch_flag_partition(int pivot_index, vector<Color> *A_ptr)
{
    auto &A = *A_ptr;
    Color p = A[pivot_index];
    int s = 0;
    int e = A.size() - 1;
    int i = -1;
    // loop 0 - move "< Pivot" to front
    while (s < e)
    {
        if (A.at(s) < p)
        {
            i++;
            s++;
        }
        else 
        {
            Color t = A[s];
            A[s] = A[e];
            A[e] = t;
            e--;
        } 
    }
    // loop 1 - move "> Pivot" to back
    i++;
    e = A.size() - 1;
    while (i < e)
    {
        if (A.at(i) > p)
        {
            Color t = A[i];
            A[i] = A[e];
            A[e] = t;
            e--;
        }
        else 
        {
            i++;
        } 
    }
}

void dutch_flag_partition(int pivot_index, vector<Color> *A_ptr)
{
    auto &A = *A_ptr;
    int pivot_val = A[pivot_index];
    int s = 0;
    int e = A.size() - 1;
    int m = -1;
    
    while (s <= e)
    {
        if (A[s] < pivot_val)
        {
            if (m >= 0)
            {
                auto t = A[s];  
                A[s] = A[m];
                A[m++] = t;
                s++;
            }
            else 
            {
                s++;
            }
        }
        else if (A[s] == pivot_val)
        {
            if (m < 0) 
            {
                m = s;
            }
            s++;
        }
        else
        {
            auto t = A[s];
            A[s] = A[e];
            A[e--] = t;
        }
    }
}

int main()
{
    {
        vector<Color> a = { kRed, kWhite, kBlue, kRed, kWhite, kBlue };
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        _dutch_flag_partition(1, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<Color> a = { kWhite, kWhite, kRed, kBlue };
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        dutch_flag_partition(1, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<Color> a = { kRed, kRed, kWhite, kBlue };
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        dutch_flag_partition(2, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<Color> a = { kBlue, kWhite, kRed, kRed };
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        dutch_flag_partition(1, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<Color> a = { kBlue, kWhite, kRed, kRed };
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        dutch_flag_partition(1, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<Color> a = { kBlue, kWhite, kWhite, kBlue, kRed, kWhite};
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        dutch_flag_partition(4, &a);
        for (auto e: a)
        {
            std::cout << e << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
