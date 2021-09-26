#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        // 1.首先进行树的层次遍历
        queue<TreeNode*> q;
        vector<int> nums;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            TreeNode* tmp;
            int val = 0;
            for(int i = 0; i < size; i++){
                tmp = q.front();
                q.pop();
                val += tmp->val;
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            nums.push_back(val);
        }
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        // 2.再动态规划
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }   
        return dp[dp.size() - 1];
    }
};

int main(){

}