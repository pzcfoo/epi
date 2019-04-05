#include <limits>


short brute_force_parity(unsigned long long x)
{
  short count = 0;
  while (x)
  {
      count = count + (x & 1);
      x = x >> 1;
  }
  return x % 2;
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

short Parity(unsigned long long x)
{
    return 0;
}

int main(int argc, char* argv[]) {
    return 0;
}
