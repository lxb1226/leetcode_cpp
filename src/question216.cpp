#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;

    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrack(1, k, n);
        return ans;
    }

    void backtrack(int num, int k, int n)
    {
        if (num == 10)
        {
            if (k == 0 && n == 0)
            {
                ans.push_back(tmp);
            }
            return;
        }

        // 不选择当前这个数
        backtrack(num + 1, k, n);

        // 选择当前这个数
        tmp.push_back(num);
        backtrack(num + 1, k - 1, n - num);
        tmp.pop_back();
    }
};

int main()
{
    int k = 3, n = 7;
    Solution su;
    auto ans = su.combinationSum3(k, n);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}