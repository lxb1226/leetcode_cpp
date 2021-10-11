#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(vector<int>& nums, int l, int r){
        // 左闭右开
        if(l == r){
            return nullptr;
        }
        int max_idx = findMax(nums, l, r);
        TreeNode* node = new TreeNode(nums[max_idx]);
        node->left = helper(nums, l, max_idx - 1);
        node->right = helper(nums, max_idx + 1, r);
        return node;
    }

    int findMax(vector<int>& nums, int l, int r){
        int max_val = -1;
        int max_idx = -1;
        for(int i = l; i < r; i++){
            if(nums[i] > max_val){
                max_val = nums[i];
                max_idx = i;
            }
        }

        return max_idx;
    }
};

int main(){

}