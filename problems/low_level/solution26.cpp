#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 解决策略1：
     * 因为是有序数组，所以遍历一遍即可，在遍历过程中比较前一个和自己的大小即可判断重复。
     * 另外，对于移动元素，可以使用一个计数器cnt，指向前面没有移动的位置的下一个，当不重复的时候（即此时需要移动元素），
     * 那么可以将元素放在cnt上面，同时将cnt++。
     */
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return nums.size();
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                // 没有重复元素
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    vector<int> nums{1, 1, 2};
    Solution solution;
    int len = solution.removeDuplicates(nums);
    for (int i = 0; i < len; i++)
        printf("%d\n", nums[i]);
    return 0;
}