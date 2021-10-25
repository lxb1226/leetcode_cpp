#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int m_min = 2000000;
public:
    // 法一：该方法超出时间限制
    int minPathSum1(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return m_min;
    }

    void dfs(vector<vector<int>>& grid,int ans, int l, int r){
        int m = grid.size() - 1, n = grid[0].size() - 1;
        // cout << "l : " << l << " r : " << r << " ans : " << ans << " m_min : " << m_min << endl;
        if(l == m && r == n){
            m_min = min(ans + grid[l][r], m_min);
            return;
        }else if(l == m && r != n){
            dfs(grid, ans + grid[l][r], l, r + 1);
        }else if(r == n && l != m){
            dfs(grid, ans + grid[l][r], l + 1, r);
        }else{
            // 向右
            dfs(grid, ans + grid[l][r], l, r + 1);
            // 向下
            dfs(grid, ans + grid[l][r], l + 1, r);
        }
        
    }

    /**
     * 法二：动态规划
     */ 
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector<vector<int>> (rows, vector<int>(columns));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < rows; i++){
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for(int j = 1; j < columns; j++){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[rows - 1][columns - 1];
    }
};

int main(){
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    auto ans = s.minPathSum(grid);
    cout << ans << endl;
    return 0;
}