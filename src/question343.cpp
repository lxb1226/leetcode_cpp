#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        // 令dp[i]表示数字i拆分后得到的最大乘积
        // dp[i] 来源于 dp[i - j] * dp[j], (i - j) * j, dp[i - j] * j, dp[j] * (i - j) 后两者一样，因此只有三种情况
        // dp[i] = max(dp[i], max(dp[i - j] * dp[j], (i - j) * j))
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; ++i){
            // 还可以简化一下
            for(int j = 1; j <= i / 2; j++){

                dp[i] = max(max(max(dp[i], max(dp[i - j] * dp[j], (i - j) * j)), dp[i - j] * j), dp[j] * (i - j));
            }
            // cout << "dp[" << i << "] : " << dp[i] << endl; 
        }
        return dp[n];
    }
};

int main(){
    int n = 8;
    Solution su;
    auto ans = su.integerBreak(n);
    cout << ans << endl;
}