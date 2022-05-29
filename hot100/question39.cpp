#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    
    vector<int> path;

    void backtrack(vector<int>& candidates, int idx, int target){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(idx >= candidates.size())
            return;
        if(candidates[idx] <= target){
            path.push_back(candidates[idx]);
            backtrack(candidates, idx, target - candidates[idx]);
            path.pop_back();
        }
        backtrack(candidates, idx + 1, target);
        


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return res;
    }
};

int main()
{
}