#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // idx指示的当前可存放的位置
        int idx = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[idx] = nums[i];
                idx++;
            }
        }

        for (int i = idx; i < n; i++)
        {
            nums[i] = 0;
        }
    }

    // 法二：双指针,双指针指代的意义不一样
    // left指代当前已经处理好的序列的尾部，right指向待处理序列的头部
    void moveZeroes1(vector<int> &nums)
    {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    Solution su;
    su.moveZeroes(nums);
    for (auto num : nums)
    {
        cout << num << " ";
    }
}