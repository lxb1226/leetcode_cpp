#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

//   Definition for a binary tree node.
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
    // 递归
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode *root, long long lower, long long upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= lower || root->val >= upper)
        {
            return false;
        }

        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }

    // 法二：中序遍历
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> stk;
        long long pre = LONG_MIN;
        while (root != nullptr || !stk.empty())
        {
            if (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                root = stk.top();
                stk.pop();
                if (root->val <= pre)
                {
                    return false;
                }
                pre = root->val;
                root = root->right;
            }
        }

        return true;
    }
};

int main()
{
}