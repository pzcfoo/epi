#include <iostream>
#include <bitset>


unsigned long long ReverseBits(unsigned long long x) 
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


int main ()
{
    unsigned long long b = 4611686018427387904;
    //unsigned long long test = 1351510410656;
    std::cout << std::bitset<64>(b) << std::endl;
    auto ans = ReverseBits(b);
    std::cout << std::bitset<64>(ans) << std::endl;
    { 
        //unsigned long long a = 10;
        //std::cout << std::bitset<64>(a) << std::endl;
        //auto ans = ReverseBits(a);
        //std::cout << std::bitset<64>(ans) << std::endl;
    }
    return 0;
}

