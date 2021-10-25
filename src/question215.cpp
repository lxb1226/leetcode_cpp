#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // 大顶堆
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto num : nums)
        {
            if (q.size() < k)
            {
                q.push(num);
            }
            else
            {
                if (num > q.top())
                {
                    q.pop();
                    q.push(num);
                }
            }
        }

        return q.top();
    }
};

int main()
{
    vector<int> nums{3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution su;
    auto ans = su.findKthLargest(nums, k);
    cout << ans << endl;
    return 0;
}