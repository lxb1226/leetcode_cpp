#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // TODO:没理解
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < n; ++i)
        {
            if (maxn > nums[i])
            {
                right = i;
            }
            else
            {
                maxn = nums[i];
            }

            if (minn < nums[n - i - 1])
            {
                left = n - i - 1;
            }
            else
            {
                minn = nums[n - i - 1];
            }
        }

        return right == -1 ? 0 : right - left + 1;
    }
};

int main()
{
    vector<int> nums{2, 6, 4, 8, 10, 9, 15};
    // vector<int> nums{1, 2, 3, 4};
    Solution su;
    auto ans = su.findUnsortedSubarray(nums);
    cout << ans << endl;
}