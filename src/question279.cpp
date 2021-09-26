#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution
{
public:
    // 方法可行，超时了
    int numSquares1(int n)
    {
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        int s = static_cast<int>(sqrt(n));
        int min_cnt = INT_MAX;
        for (int i = s; i >= 1; i--)
        {
            min_cnt = min(numSquares(n - i * i) + 1, min_cnt);
        }
        return min_cnt;
    }

    // 动态规划 思路和我的想法有点类似
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }

        return f[n];
    }
};

int main()
{
    int n = 13;
    Solution su;
    auto ans = su.numSquares(n);
    cout << ans << endl;
}