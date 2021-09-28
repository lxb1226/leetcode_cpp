#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // TODO:构建前缀和
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &x : nums)
        {
            pre += x;

            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }

        return count;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};
    int k = 3;
    Solution su;
    auto ans = su.subarraySum(nums, k);
    cout << ans << endl;
}