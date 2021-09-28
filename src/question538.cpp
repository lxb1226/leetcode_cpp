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
    // 右中左遍历顺序
    TreeNode *convertBST(TreeNode *root)
    {
        int pre_val = 0;
        travel(root, pre_val);
        return root;
    }

    void travel(TreeNode *root, int &pre_val)
    {
        if (root == nullptr)
        {
            return;
        }
        travel(root->right, pre_val);
        root->val += pre_val;
        pre_val = root->val;
        travel(root->left, pre_val);
    }
};

int main()
{
}