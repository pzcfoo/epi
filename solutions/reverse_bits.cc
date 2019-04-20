#include <iostream>
#include <bitset>


unsigned long long BruteForceReverseBits(unsigned long long x) 
{
    unsigned long long ans = 0;
    int l = 63; 
    short i = 0; // tracks corresponding reversed position
    
    if (x & 1)
    {
        unsigned long long mask = 1ULL << (l - i); 
        ans |= mask;
    }
    while(x)
    {
        i++;
        x = x >> 1;
        if (x & 1)
        {
            unsigned long long mask = 1ULL << (l - i); 
            ans |= mask;
        }
    }
    return ans;
}

// slightly better
unsigned long long ReverseBits(unsigned long long x)
{
    unsigned long long ans = x;
    int l = 63;
    for (int i=0; i < 32; i++)
    {
        int j = (l - i);
        int val_i = (x >> i) & 1;
        int val_j = (x >> j) & 1;
        if (val_i != val_j)
        {
            unsigned long long mask = 1ULL << i;
            mask |= (1ULL << j);
            ans ^= mask;
        }
    }
    return ans;
}



int main ()
{
    unsigned long long test = 1351510410656;
    std::cout << std::bitset<64>(test) << std::endl;
    auto ans = ReverseBits(test);
    std::cout << std::bitset<64>(ans) << std::endl;
    return 0;
}

