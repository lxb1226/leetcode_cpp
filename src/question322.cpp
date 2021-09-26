#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // 贪心算法
    // TODO：超出了时间限制，意料之中
    int coinChange(vector<int>& coins, int amount) {
        int cnt = 0, min_cnt = INT_MAX;
        helper(coins, amount, cnt, min_cnt);
        return min_cnt == INT_MAX ? -1 : min_cnt;
    }

    void helper(vector<int>& coins, int amount, int cnt, int& min_cnt){
        if(amount == 0){
            min_cnt = min(cnt, min_cnt);
            return;
        }
        if(amount < 0){
            return;
        }  
        for(int i = coins.size() - 1; i >= 0; i--){
            helper(coins, amount - coins[i], cnt + 1, min_cnt);
        }

    }

    // 动态规划
    // TODO:待看
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < static_cast<int>(coins.size()); ++j){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(){
    // vector<int> coins{1, 2, 5};
    // int amount = 11;

    vector<int> coins{2};
    int amount = 3;

    Solution su;
    auto ans = su.coinChange(coins, amount);
    cout << ans << endl;
}