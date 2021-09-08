#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TODO:不想写
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int len = nums.size();
        dfs(nums, ans, tmp, len);
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, int len){
        if(tmp.size() == len){
            ans.push_back(tmp);
        }
        // 选这个
        tmp.push_back(nums[0]);
        
        
        // 不选这个

    }
};

int main(){

}