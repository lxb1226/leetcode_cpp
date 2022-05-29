#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower){
        int l = 0, r = nums.size() - 1;
        int ans = nums.size();
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
        int rightIdx = binarySearch(nums, target, false) - 1;
        if(leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target){
            return {leftIdx, rightIdx};
        }
        return {-1, -1};
    }
};

int main()
{
}