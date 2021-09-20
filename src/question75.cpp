#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    // TODO：考虑使用双指针法
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[i], nums[p1]);
                ++p1;
            }else if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                if(p0 < p1){
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
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