#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, static_cast<int>(nums.size()));
        return ans;
        
    }

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
        if(first == len){
            res.emplace_back(output);
            return;
        }

        for(int i = first; i < len; ++i){
            swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            swap(output[i], output[first]);
        }
    }

    
};

int main(){
    vector<int> nums{1, 2, 3};
    Solution s;
    auto ans = s.permute(nums);
    for(auto num : ans){
        for(auto n : num){
            cout << n << " ";
        }
        cout << endl;
    }
}