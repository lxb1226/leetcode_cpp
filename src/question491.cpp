#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtrack(nums, 0, INT_MIN);
        return ans;
    }

    void backtrack(vector<int> &nums, int idx, int last)
    {
        if (idx == nums.size())
        {
            if (tmp.size() >= 2)
                ans.push_back(tmp);
            return;
        }

        if (nums[idx] >= last)
        {
            tmp.push_back(nums[idx]);
            backtrack(nums, idx + 1, nums[idx]);
            tmp.pop_back();
        }

        // 只有当当前元素不等于上一个选择的元素的时候，才考虑不选择当前元素，直接递归后面的元素

        if (nums[idx] != last)
        {
            backtrack(nums, idx + 1, last);
        }
    }
};

int main()
{
    vector<int> nums{4, 6, 7, 7};
    Solution su;
    auto ans = su.findSubsequences(nums);
    for (auto ints : ans)
    {
        for (auto num : ints)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}