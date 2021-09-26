#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TODO:
    // 法一：二分查找,时间复杂度O(nlogn)，空间复杂度O(1),感觉太浪费时间了
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int l = 1, r = n - 1, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                cnt += nums[i] <= mid;
            }

            if (cnt <= mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }

    // 法二：二进制
    // TODO：待看，涉及到了位运算
    int findDuplicate1(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        int bit_max = 31;
        while (!(n - 1) >> bit_max)
        {
            bit_max -= 1;
        }

        for (int bit = 0; bit <= bit_max; ++bit)
        {
            int x = 0, y = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] & (1 << bit))
                {
                    x += 1;
                }
                if (i >= 1 && (i & (1 << bit)))
                {
                    y += 1;
                }
            }

            if (x > y)
            {
                ans |= 1 << bit;
            }
        }

        return ans;
    }

    // 法三：快慢指针
    // TODO: 看不懂
    int findDuplicate2(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{
    vector<int> nums{1, 3, 4, 2, 2};
    Solution su;
    auto ans = su.findDuplicate(nums);
    cout << ans << endl;
}