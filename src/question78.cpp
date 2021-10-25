#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>{});
        
        vector<int> tmp;
        dfs(nums, ans, tmp, 0);

        return ans;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, int idx){
        if(idx == nums.size())
            return;
        
        for(int i = idx; i < nums.size(); i++){
            // 添加当前元素
            tmp.push_back(nums[i]);
            ans.push_back(tmp);
            dfs(nums, ans, tmp, i + 1);
            tmp.pop_back();
        }
    }
};

int main(){
    vector<int> nums{};
    Solution s;
    auto ans = s.subsets(nums);
    for(auto m : ans){
        for(auto n : m){
            cout << n << " ";
        }
        cout << endl;
    }

}