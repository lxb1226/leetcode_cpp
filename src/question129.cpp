#include <iostream>
#include <vector>

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
    int sumNumbers(TreeNode* root) {
        int val = 0, total_val = 0;
        if(root == nullptr)
            return 0;
        dfs(root, val, total_val);
        return total_val;
    }

    void dfs(TreeNode* node, int val, int& total_val){
        if(node->left == nullptr && node->right == nullptr){
            val = val * 10 + node->val;
            // cout << val << endl;
            total_val += val;
            return;
        }
        val = val * 10 + node->val;
        if(node->left){
            dfs(node->left, val, total_val);
        }

        if(node->right){
            dfs(node->right, val, total_val);
        }
    }
};

TreeNode* buildTree(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    return root;
}

int main(){
    TreeNode* root = buildTree();
    Solution su;
    auto ans = su.sumNumbers(root);
    cout << ans << endl;
}