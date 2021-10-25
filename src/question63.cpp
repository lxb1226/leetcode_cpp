#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // TODO:有bug
    int uniquePathsWithObstacles1(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector<int> f(m);
        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (obstacleGrid[i][j] = 1)
                {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                {
                    f[j] += f[j - 1];
                }
            }
        }

        return f.back();
    }
    // TODO:使用动态规划
    vector<vector<int>> directions{{1, 0}, {0, 1}}; //下右
    // dfs
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1 && obstacleGrid[0][0] == 1)
            return 0;
        int i = 0, j = 0, path = 0;
        dfs(obstacleGrid, i, j, path);
        return path;
    }

    //
    void dfs(vector<vector<int>> &grid, int i, int j, int &path)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            path++;
            // cout << path << endl;
            return;
        }

        for (int k = 0; k < 2; ++k)
        {
            i += directions[k][0];
            j += directions[k][1];
            if (valid(i, j, grid.size(), grid[0].size()) && grid[i][j] != 1)
            {
                grid[i][j] = 1;
                // cout << "i = " << i << " j = " << j << endl;
                dfs(grid, i, j, path);
                grid[i][j] = 0;
            }
            i -= directions[k][0];
            j -= directions[k][1];
        }
    }

    bool valid(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};

int main()
{
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution su;

    auto ans = su.uniquePathsWithObstacles(grid);
    cout << ans << endl;
}