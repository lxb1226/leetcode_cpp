#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TODO：这道题非常有意思，在使用二分查找的时候考虑边界问题，对于使用二分查找是个很好的练习
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            // cout << "mid : " << mid << endl;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                if(nums[mid] > nums[r]){
                    // 左侧有序
                    l = mid + 1;
                }else{
                    // 右侧有序
                    if(nums[r] >= target){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                    
                }
            }else{
                if(nums[mid] > nums[r]){
                    // 左侧有序
                    if(nums[l] > target){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }else{
                    // 右侧有序
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main(){

    // vector<int> nums{4,5,6,7,0,1,2};
    // vector<int> nums{1};

    vector<int> nums{1,3};
    int target = 3;
    Solution s;
    auto ans = s.search(nums, target);
    cout << ans << endl;

}