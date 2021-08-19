#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /**
         * 解决方法1：暴力遍历，时间复杂度：O(n^2)
         */
        bool flag = false;
        int i, j;
        for (i = 0; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        return {i, j};
    }

    /**
     * 解决策略2：使用哈希表。时间复杂度：O(n) 空间复杂度:O(n)
     * 前一个方法的时间复杂度主要用在寻找target - nums[i]。
     * 因此可以使用哈希表快速寻找数组是否存在目标元素。
     * 
     * 这样我们创建一个哈希表。对于每一个x，都先在哈希表中查找是否有target - nums[i]。
     * 如果没有的话，则将其存入哈希表。
     */
    vector<int> twoSum2(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
                return {it->second, i};
            hashtable[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> ans = solution.twoSum2(nums, target);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}