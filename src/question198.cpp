#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int maxMoney;
public:

    // 动态规划
    // TODO:需要做第二遍
    int rob(vector<int>& nums){
        if(nums.size() == 0){
            return 0;
        }

        int size = nums.size();
        if(size == 1){
            return nums[0];
        }

        vector<int> dp = vector<int>(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }

    // 回溯法
    int rob1(vector<int>& nums) {
        maxMoney = 0;
        dfs(nums, 0, 0, true);
        return maxMoney;
    }

    void dfs(vector<int>& nums, int money, int idx, bool flag){
        if(idx > nums.size()){
            maxMoney = max(money, maxMoney);
            return;
        }

        if(flag){
            // flag 为true，可以选择偷和不偷
            // 偷这家
            dfs(nums, money + nums[idx], idx + 1, !flag);

            // 不偷这家
            dfs(nums, money, idx + 1, flag);
        }else{
            // flag为false 不能偷
            dfs(nums, money, idx + 1, !flag);
        }
    }
};

int main(){

    vector<int> nums{1, 2, 3, 1};
    // vector<int> nums{2, 7, 9, 3, 1};
    Solution s;
    auto ans = s.rob(nums);
    cout << ans << endl;

}