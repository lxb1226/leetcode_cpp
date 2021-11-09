#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // 版本一
    int minCostClimbingStairs(vector<int>& cost) {
        // 令dp[i]表示爬到i的最低花费
        // 则dp[i] = min(dp[i - 1] + costs[i - 1], dp[i - 2] + costs[i - 2]);
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= n; ++i){
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }

    // 版本二：由于状态转移方程中只依赖于前两个状态，因此只保留前两个状态就可以节省空间
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp0 = 0, dp1 = 0;
        for(int i = 2; i <= n; ++i){
            int tmp = dp1;
            dp1 = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
            dp0 = tmp;
        }
        return dp1;
    }
};

int main(){

}