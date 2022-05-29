#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (hashtable.count(target - num) == 0)
            {
                hashtable[num] = i;
            }
            else
            {
                return {hashtable[target - num], i};
            }
        }
        return {};
    }
};

int main()
{
}