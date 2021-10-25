#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 法一：
    vector<int> searchRange1(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(nums[mid] == target){
                break;
            }else if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        // cout << "mid = " << mid << endl;
        if(l > r) return {-1, -1};
        int i = mid, j = mid;
        while(i >= 0 && nums[i] == target) i--;
        while(j < nums.size() && nums[j] == target) j++;
        return {i + 1, j - 1};
    }

    // 法二：
    int binarySearch(vector<int>& nums, int target, bool lower){
        int l = 0, r = nums.size() - 1, ans = nums.size();
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] > target || (lower && nums[mid] >= target)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false);
        if(leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target){
            return vector<int>{leftIdx, rightIdx};
        }
        return {-1, -1};
    }
};

int main(){
    // vector<int> nums{5,7,7,8,8,10};
    // int target = 8;

    vector<int> nums{5,7,7,8,8,10};
    int target = 6;

    Solution s;
    auto ans = s.searchRange(nums, target);
    for(auto num : ans){
        cout << num << " ";
    }
    cout << endl;
}