#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 动态规划 
    // TODO:还可以进一步优化空间
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(nums);
        vector<int> dp_min(nums);
        
        for(int i = 1; i < n; i++){
            dp_max[i] = max(dp_max[i - 1] * nums[i], max(nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(dp_min[i - 1] * nums[i], min(nums[i], dp_max[i - 1] * nums[i]));
        }

        return *max_element(dp_max.begin(), dp_max.end());

    }
};

int main(){
    vector<int> nums{2, 3, -2, 4};
    Solution su;
    auto ans = su.maxProduct(nums);
    cout << ans << endl;
}