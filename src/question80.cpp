#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0, cnt = 1;// len表示下一个可放置的位置
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                // 如果两者相等，那么cnt++
                cnt++;
            }else{
                if(cnt > 2){
                    // 说明有3个以上，减到两个就可以
                    cnt = 2;
                }
                // 说明在3个以下，全部移动
                while(cnt > 0){
                    nums[len++] = nums[i - cnt];
                    cnt--;
                }
                cnt = 1;
            }
        }

        return len;
    }
};

int main(){
    vector<int> nums{1, 1, 1, 2, 2, 3};
    Solution su;
    auto len = su.removeDuplicates(nums);
    for(int i = 0; i < len ; i++){
        cout << nums[i] << " ";
    }
    return 0;

}