#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    // TODO：考虑使用双指针法
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r){
            while(nums[r] != 0 && r >= 0) --r;
            while(nums[l] != 2 && l < nums.size()) ++l;
            
            swap(nums[l], nums[r]);
        }
    }
    
    
};

int main(){

    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(nums);
    for(auto num : nums)
        cout << num << " ";
    cout << endl;
    return 0;
}