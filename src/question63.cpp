#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 版本一： 动态规划
    int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化
        for(int i = 0; i < m; i++){
            if(!obstacleGrid[i][0]){
                dp[i][0] = 1;
            }else{
                break;
            }
        }

        for(int i = 0; i < n; ++i){
            if(!obstacleGrid[0][i]){
                dp[0][i] = 1;
            }else{
                break;
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // 版本二： 使用滚动数组来降维
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = (obstacleGrid[0][0] == 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }
                if(j - 1 >= 0 && obstacleGrid[i][j- 1] == 0){
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }

    // 版本三：回溯

};

int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution su;

    auto ans = su.uniquePathsWithObstacles(grid);
    cout << ans << endl;
}