#include "test_framework/generic_test.h"

short CountBits(unsigned int x)
{
    short count = 0;
    while (x)
    {
        if (x & 1)
        {
          count++;
        }
        x = x >> 1;
    }
    return count;
}

int main(int argc, char* argv[])
{
    return 0;
}
