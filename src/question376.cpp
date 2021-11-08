#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 1.贪心
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return;
        }

        int prevdiff = nums[1] - nums[0];
        int ret = prevdiff != 0 ? 2 : 1;
        for (int i = 2; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0))
            {
                ret++;
                prevdiff = diff;
            }
        }
        return ret;
    }
};

int main()
{
}