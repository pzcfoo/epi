#include <iostream>
#include <vector>

using std::vector;
void plus_one(vector<int> &A) {
    bool overflow = false;
    int s = A.size() -1;
    for (int i=s; i >=0 ; i--)
    {
        int val = A[i] + 1;
        if (val > 9)
        {
            A[i] = 0;
            if (i==0)
            {
                overflow = true;
            }
        }
        else
        {
            A[i]++;        
            break;
        } 
    }
    if (overflow)
    {
        A[0] = 1;
        A.push_back(0);
    }
}

int main(int argc, char* argv[])
{
    {
        vector<int> a = {9};
        for (auto e: a)
            std::cout << e << " ";
        std::cout << std::endl;
        plus_one(a);
        for (auto e: a)
            std::cout << e << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        vector<int> a = {9, 9, 9};
        for (auto e: a)
            std::cout << e << " ";
        std::cout << std::endl;
        plus_one(a);
        for (auto e: a)
            std::cout << e << " ";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
