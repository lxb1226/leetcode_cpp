#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<int> vis;

    void dfs(vector<int>& nums, int idx, int diff){
        if(diff == 0){
            ans.push_back(tmp);
            return;
        }
        if(idx == nums.size()){
            return;
        }
        if(diff - nums[idx] >= 0){
            if(!(vis[idx] || (idx > 0 && nums[idx] == nums[idx-1] && !vis[idx-1]))){
                tmp.push_back(nums[idx]);
                vis[idx] = 1;
                dfs(nums, idx + 1, diff - nums[idx]);
                vis[idx] = 0;
                tmp.pop_back();
            }
        }

        dfs(nums, idx + 1, diff);
    }
public:
    // TODO：待看
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vis.resize(candidates.size());
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};

int main(){
    vector<int> candidates{10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    auto ans = s.combinationSum2(candidates, target);
    for(auto nums : ans){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}