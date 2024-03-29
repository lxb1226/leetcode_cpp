#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx){
        if(idx == candidates.size()){
            return;
        }
        if(target == 0){
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if(target - candidates[idx] >= 0){
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

};

int main(){
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    Solution s;
    auto ans = s.combinationSum(candidates, target);
    for(auto nums : ans){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}