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

class Solution
{
public:
    // TODO:中序遍历的迭代写法， 二叉树的遍历的迭代写法需要掌握
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode *> stk;
        TreeNode *x = nullptr;
        TreeNode *y = nullptr;
        TreeNode *pred = nullptr;

        while (!stk.empty() || root != nullptr)
        {
            while (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            if (pred != nullptr && root->val < pred->val)
            {
                y = root;
                if (x == nullptr)
                {
                    x = pred;
                }
                else
                {
                    break;
                }
            }

            pred = root;
            root = root->right;
        }

        swap(x->val, y->val);
    }
};

TreeNode *buildTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    return root;
}

int main()
{
    TreeNode *root = buildTree();
    Solution su;
    su.recoverTree(root);
}