#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 版本一
    int uniquePaths1(int m, int n) {
        // 令dp[i][j]表示(0,0)到(i,j)的路径
        // 状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j - 1]
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i-1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // 版本二
    // 考虑到dp[i][j]只依赖于前一行，以及前一个的值，因此可以简化到一维
    int uniquePaths2(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }

    // 版本三： 回溯 超时
    int uniquePaths(int m, int n) {
        int total = 0;
        backtrack(0, 0, m, n, total);
        return total;
    }

    void backtrack(int row, int col, int m, int n, int& total){
        if(row == m - 1 && col == n - 1){
            total += 1;
            return;
        }
        if(row == m || col == n){
            return;
        }
        backtrack(row + 1, col, m, n, total);
        backtrack(row, col + 1, m, n, total);
    }

};

int main(){
    int m = 7, n = 3;
    Solution s;
    auto ans = s.uniquePaths(m, n);
    cout << ans << endl;
}