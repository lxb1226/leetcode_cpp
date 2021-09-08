#include <iostream>
#include <vector>


using namespace std;

/**
 * 异或运算有以下三个性质：
 * 1.任何数和0做异或运算，结果仍然是原来的数。
 * 2.任何数和其自身做异或运算，结果是0。
 * 3.异或运算满足交换律和结合律。
 */  

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num : nums){
            // 异或运算
            res ^= num;
        }
        return res;
    }
};

int main(){
    // vector<int> nums{2,2,1};
    vector<int> nums{4, 1, 2, 1, 2};
    Solution s;
    auto res = s.singleNumber(nums);
    cout << res << endl;
}