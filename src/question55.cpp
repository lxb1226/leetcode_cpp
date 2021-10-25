#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TODO:贪心算法
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for(int i = 0; i < n; ++i){
            if(i <= rightmost){
                rightmost = max(rightmost, i + nums[i]);
                if(rightmost >= n - 1){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    vector<int> nums{2, 3, 1, 1, 4};
    Solution su;
    auto ans = su.canJump(nums);
    cout << ans << endl;
}