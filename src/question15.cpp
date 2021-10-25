#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // TODO:需要做第二遍
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        // 枚举a
        for(int first = 0; first < n; ++first){
            // 需要和上一次枚举的数不相同
            if(first > 0 && nums[first] == nums[first - 1]) continue;

            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];

            // 枚举b
            for(int second = first + 1; second < n; ++second){
                // 需要和上一次枚举的数不同
                if(second > first + 1 && nums[second] == nums[second - 1])continue;

                // 需要保证b的指针在c的指针的左侧
                while(second < third && nums[second] + nums[third] > target) --third;

                // 如果指针重合，随着b后续的增加，就不会有满足a+b+c=0并且b<c的c了，可以退出循环
                if(second == third)break;

                if(nums[second] + nums[third] == target){
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution s;
    auto ans = s.threeSum(nums);
    for(auto nums : ans){
        for(auto num : nums){
            cout << " " << num;
        }
        cout << endl;
    }
}