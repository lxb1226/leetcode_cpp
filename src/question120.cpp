#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    // TODO:
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> f(n);
        f[0] = triangle[0][0];
        for(int i = 1; i < n; ++i){
            f[i] = f[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; --j){
                f[j] = min(f[j-1], f[j]) + triangle[i][j];
            }

            f[0] += triangle[i][0];
        }

        return *min_element(f.begin(), f.end());
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++){ 
            for(int j = 0; j <= i; j++){
                if(j > 0 && j < i){
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
                }else if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }else if(j == i){
                    dp[i][j] = dp[i-1][j - 1] + triangle[i][j];
                }
                
            }
        }

        // 遍历最后一行，得出最小的值
        int min_val = INT_MAX;
        for(int i = 0; i < n; i++){
            if(dp[n - 1][i] < min_val){
                min_val = dp[n - 1][i];
            }
        }

        // for(auto nums : dp){
        //     for(auto num : nums){
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }

        return min_val;
    }
};

int main(){
    vector<vector<int>> nums = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution su;
    auto ans = su.minimumTotal(nums);
    cout << ans << endl;
    return 0;
}