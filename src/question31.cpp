#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // TODO:待看，解析看的不是很明白
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i >= 0){
            int j = nums.size() - 1;
            while(j >= 0 && nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main(){
    // vector<int> nums{1, 2, 3};
    vector<int> nums{1, 3, 2};

    Solution s;
    s.nextPermutation(nums);
    for(auto num : nums){
        cout << " " << num;
    }
    cout << endl;
    return 0;
}