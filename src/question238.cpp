#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer(n, 1);
        for(int i = 1; i < n; i++){
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int R = 1;
        for(int i = n - 1; i >= 0; i--){
            answer[i] = answer[i] * R;
            R *= nums[i];
        }

        return answer;
    }
};

int main(){
    vector<int> nums{1, 2, 3, 4};
    Solution su;
    auto ans = su.productExceptSelf(nums);
    for(auto num : ans){
        cout << num << " ";
    }
    cout << endl;
}