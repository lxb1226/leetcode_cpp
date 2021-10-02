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

class Solution
{
public:
    // TODO:
    void recoverTree(TreeNode *root)
    {
    }

    // 中序遍历
    void in_order(TreeNode *root, int &pre_val, int &val)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val < pre_val)
        {
            val = root->val;
            return;
        }
        pre_val = root->val;
        in_order(root->left, pre_val, val);
        in_order(root->right, pre_val, val);
    }
};

int main()
{
}