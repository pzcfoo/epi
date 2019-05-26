#include <iostream>
#include <vector>
using std::vector;


void print_vec(vector<int> &a)
{
    for (auto e: a)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}


void _add_int_vector(vector<int> &a, vector<int> &b)
{
    // assume same size
    // will be changed in place for a;
    int overflow = 0;
    for (int i=b.size()-1; i >= 0; i--)
    {
        int val = a[i] + b[i] + overflow;          
        if (val > 9)
        {
            overflow = 1;
            a[i] = val % 10;
        }
        else
        {
            overflow = 0; 
            a[i] = val;
        }
    }
}

vector<int> optimised_multiply(vector<int> num1, vector<int> num2)
{
    if ((num1.size() == 1 && num1[0] == 0) || (num2.size() == 1 && num2[0] == 0))
    {
        return {0};
    }
    int ans_size = num1.size() + num2.size();
    auto ans = vector<int>(ans_size, 0);
    auto& a = num1.size() > num2.size() ? num1 : num2;
    auto& b = num1.size() > num2.size() ? num2 : num1;

    int neg = 0;
    if (a[0] < 0)
    {
        neg ^= 1;
        a[0] = a[0] * -1;
    }
    if (b[0] < 0)
    {
        neg ^= 1;
        b[0] = b[0] * -1;
    }

    int ix = ans_size - 1;
    for (auto l_it = b.rbegin(); l_it != b.rend(); l_it++)
    {
        int ix_ = ix;
        int o = 0;
        for (auto k_it = a.rbegin(); k_it != a.rend(); k_it++)
        {
            int m = (*l_it) * (*k_it) + o + ans[ix_];
            int v = m % 10;
            o = m / 10;
            ans[ix_] = v; 
            ix_--;
        }
        if (o)
        {
            ans[ix_] = o;
        }
        ix--;
    }
    if (ans[0] == 0)
    {
        ans.erase(ans.begin());
    }
    if (neg)
    {
        ans[0] = ans[0] * -1;
    }
    return ans;
}


vector<int> multiply(vector<int> num1, vector<int> num2)
{
    auto ans = vector<int>();
    int ans_size = num1.size() + num2.size();
    int mulitply_layer = 0;
    
    if (
        (num1.size() == 1 && num1[0] == 0)
        || (num2.size() == 1 && num2[0] == 0)
       )
    {
        return {0};
    }

    for (int i = 0; i < ans_size; i++) 
    {
        ans.push_back(0);
    }
    
    auto& a = num1.size() > num2.size() ? num1 : num2;
    auto& b = num1.size() > num2.size() ? num2 : num1;

    int neg = 0;
    if (a[0] < 0)
    {
        neg ^= 1;
        a[0] = a[0] * -1;
    }
    if (b[0] < 0)
    {
        neg ^= 1;
        b[0] = b[0] * -1;
    }

    for (auto l_it = a.rbegin(); l_it != a.rend(); l_it++)
    {
        auto l = *l_it;
        auto t = vector<int>();  
        for (int i = 0; i < ans_size; i++)
        {
            t.push_back(0);
        }
        int c = t.size() - 1 - mulitply_layer;
        int overflow = 0;
        
        for (auto k_it = b.rbegin(); k_it != b.rend(); k_it++)
        {
            auto k = *k_it;
            int val = l * k + overflow;  
            if (val > 9)
            {
                overflow = val / 10;
                t[c--] = val % 10;
            }
            else
            {
                overflow = 0;
                t[c--] = val;
            }
        }
        if (overflow)
        {
            t[c] = overflow;
        }
        mulitply_layer++;
        _add_int_vector(ans, t);
        print_vec(t);
    }
    if (ans[0] == 0)
    {
        ans.erase(ans.begin());
    }
    if (neg)
    {
        ans[0] = ans[0] * -1;
    }
    return ans;
}



int main()
{
    {
        vector<int> a = {1,2,3};
        vector<int> b = {1,2,3};
        auto ans = optimised_multiply(a, b);
        print_vec(ans);
    }
    return 0;
} 

