#include <iostream>
#include <vector>
#include <stack>

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
    // 考察的是二叉树的中序遍历的非递归写法
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        while(!stk.empty() || root != nullptr){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            if(!stk.empty()){
                root = stk.top();
                stk.pop();
                k--;
                if(k == 0){
                    break;
                }
                root = root->right;
            }
            
        }
        return root->val;
    }
};

TreeNode* buildTree(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    return root;
}

int main(){
    TreeNode* root = buildTree();
    Solution su;
    int k = 1;
    auto ans = su.kthSmallest(root, k);
    cout << ans << endl;
}