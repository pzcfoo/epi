#include <limits>


short brute_force_parity(unsigned long long x)
{
    short result = 0;
    while (x)
    {
        result ^= x & 1;
        x = x >> 1;
    }
    return result;
}

short improved_parity(unsigned long long x)
{
    short count = 0;
    while (x)
    {
        count++;
        x = x & (x-1);
    }
    return count % 2 ? 1 : 0;
}

short optimal_parity(unsigned long long x)
{
    short shift = 32;
    while (shift >= 1)
    {
        x ^= x >> shift;
        shift /= 2;
    }
    return x & 1;
}


int main(int argc, char* argv[]) {
    return 0;
}
