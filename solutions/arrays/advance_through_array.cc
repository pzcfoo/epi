#include <iostream>
#include <vector>
#include <set>
using std::set;
using std::vector;

bool can_reach_end(const vector<int>& max_advance_steps)
{
    if (max_advance_steps.size() == 1)
    {
        return true;
    }
    auto set_ = set<int>();
    auto ix_end = max_advance_steps.size() - 1;
    std::cout << ix_end << std::endl;
    for (int i = 0; i < max_advance_steps.size(); i++)
    {
        auto steps = max_advance_steps[i];
        for (int j=1; j <= steps; j++)
        {
            auto ix_next = j + i;
            if (ix_next == ix_end)
            {
                return true;
            }
            set_.insert(ix_next);
        }
        auto next_pos = i+1;
        if (!set_.count(next_pos))
        {
            break;
        }
    }
    return false;
}

// O(1) space instead of O(n)
bool opt_can_reach_end(const vector<int>& max_advance_steps)
{
    if (max_advance_steps.size() == 1)
    {
        return true;
    }
    auto ix_end = max_advance_steps.size() - 1;
    int max = 0; // max ix we can get to
    for (int i = 0; (i < max_advance_steps.size()) && (max >= i); i++)
    {
        int current_max_ix = i + max_advance_steps[i];
        max = max > current_max_ix ? max : current_max_ix;
    }

    return max >= ix_end;
}


int main()
{
    {
        vector<int> a = {3,3,1,0,2,0,1};
        auto ans = opt_can_reach_end(a);
        std::cout << "case 0: " << ans << std::endl; 
    }
    {
      vector<int> a = {0};
        auto ans = opt_can_reach_end(a);
        std::cout << "case 1: " << ans << std::endl; 
    }
    {
        vector<int> a = {0, 0};
        auto ans = opt_can_reach_end(a);
        std::cout << "case 2: " << ans << std::endl; 
    }
    {
        vector<int> a = {1, 0, 0};
        auto ans = opt_can_reach_end(a);
        std::cout << "case 3: " << ans << std::endl; 
    }
}

