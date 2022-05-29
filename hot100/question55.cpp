#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= maxLen)
            {
                maxLen = max(maxLen, i + nums[i]);
                if (maxLen >= n - 1)
                    return true;
            }
        }

        return false;
    }
};

int main()
{
}