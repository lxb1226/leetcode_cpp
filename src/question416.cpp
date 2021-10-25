#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    // 法二：优化
    bool canPartition1(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());

        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            for (int j = target; j >= num; --j)
            {
                dp[j] |= dp[j - num];
            }
        }

        return dp[target];
    }

    // 法一：动态规划
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());

        if (sum & 1)
        {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target)
        {
            return false;
        }
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            int num = nums[i];
            for (int j = 1; j <= target; j++)
            {
                if (j >= num)
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

int main()
{
    vector<int> nums{1, 5, 11, 5};
    Solution su;
    auto ans = su.canPartition(nums);
    cout << ans << endl;
    return 0;
}