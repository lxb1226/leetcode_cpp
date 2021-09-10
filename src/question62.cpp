#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 动态规划
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            paths[i][0] = 1;
        }

        for(int j = 0; j < n; j++){
            paths[0][j] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                paths[i][j] = paths[i][j - 1] + paths[i - 1][j]; 
            }
        }

        return paths[m - 1][n - 1];
    }
};

int main(){
    int m = 7, n = 3;
    Solution s;
    auto ans = s.uniquePaths(m, n);
    cout << ans << endl;
}