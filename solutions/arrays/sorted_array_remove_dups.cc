#include <iostream>
#include <optional>
#include <vector>
#include "../helpers.h"

using std::vector;
using std::optional;

int _set_dupes_to_zero(vector<int> &a)
{
    int count = 0;
    int prev = -1;
    for (int i = 0; i < a.size(); i ++)
    {
        if (i == 0)
        {
            prev = a[i];
        }
        else
        {
            if (a[i] == prev)
            {
                a[i] = 0;
                count++;
            }
            else
            {
                prev = a[i];
            }
        }
    }
    return count;
}


void _move_non_dupes(vector<int> &a, int dupe_sentinel=0)
{
    // retains ordering and moves dupes to the back dupes are zeros
    optional<int> dupe_ix = {};
    for (int i = 0; i < a.size(); i++)
    {
        if ((!dupe_ix.has_value()) && (a[i] == dupe_sentinel))
        {
            dupe_ix = i; 
        }
        else if (dupe_ix.has_value() && a[i] != dupe_sentinel)
        {
            auto temp = a[i]; 
            a[i] = a[dupe_ix.value()];
            a[dupe_ix.value()] = temp;
            dupe_ix.value()++;
        }
    }
}


int delete_duplicates(vector<int>* A_ptr)
{
    auto &a = *A_ptr;
    auto num_dupes = _set_dupes_to_zero(a);
    auto non_dupes = a.size() - num_dupes;
    _move_non_dupes(a, 0);
    return non_dupes;
}


int delete_duplicates_optimal(vector<int>* A_ptr)
{
    // setup
    auto &a = *A_ptr;
    optional<int> dupe_ix = {};
    if (a.size() == 0)
    {
        return 0;
    }
    int prev = a[0];
    int dupe_count = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if ((a[i] == prev) && (!dupe_ix.has_value()))
        {
            dupe_count++;
            dupe_ix = i;
        }
        else if ((a[i] != prev) && (dupe_ix.has_value()))
        {
            auto t = a[i];
            a[i] = a[dupe_ix.value()];
            a[dupe_ix.value()] = t;
            dupe_ix.value()++;
            prev = t; 
        }
        else if (a[i] == prev)
        {
            dupe_count++;
        }
        else if (a[i] != prev)
        {
            prev = a[i];
        } 
        
    }
    return a.size() - dupe_count;
}


int main()
{
    {
        vector<int> a = {1,1,2,2,3,3,4,5};
        print_vec(a);
        auto num_non_dupes = delete_duplicates_optimal(&a);
        print_vec(a);
        std::cout << "non_dupes: " << num_non_dupes << std::endl;
    }
    {
        vector<int> a = {-28,-27,-26,-25,-24,-22,-21,-19,-18,-17,-15,-14,-13,-12,-11,-10,-8,-4,-2,-1,0,1,3,4,7,8,10,11,12,13,14,15,17,18,19,20,22,25,26};
        print_vec(a);
        auto num_non_dupes = delete_duplicates_optimal(&a);
        print_vec(a);
        std::cout << "non_dupes: " << num_non_dupes << std::endl;
    }
    
    {
        vector<int> a = {-8,-7,-6,-5,-5,-4,-3,-1,-1,0,0,2,2,2,4};
        print_vec(a);
        auto num_non_dupes = delete_duplicates_optimal(&a);
        print_vec(a);
        std::cout << "non_dupes: " << num_non_dupes << std::endl;
    }
    return 0;
}
