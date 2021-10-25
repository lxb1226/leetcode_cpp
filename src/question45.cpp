#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int jump(vector<int>& nums) {
        int max_far = 0;    // 目前能跳到的最远位置
        int step = 0;       // 跳跃次数
        int end = 0;        // 上次跳跃可达范围右边界（下次的最右起跳点）
        for(int i = 0; i < nums.size() - 1; i++){
            max_far = std::max(max_far, i + nums[i]);
            // 到达上次跳跃能到达的右边界了
            if(i == end){
                end = max_far;      // 目前能跳到的最远位置变成了下次起跳位置的右边界
                step++;     // 进入下一次跳跃
            }
        }
        return step;
    } 
};

int main(){
    // vector<int> nums{2,3,1,1,4};
    // vector<int> nums{2,3,0,1,4};
    vector<int> nums{2, 1};
    Solution s;
    auto ans = s.jump(nums);
    cout << ans << endl;
    return 0;
}