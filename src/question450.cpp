#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 二叉树结点结构
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
    int successor(TreeNode *root)
    {
        root = root->right;
        while (root->left != nullptr)
            root = root->left;
        return root->val;
    }

    int predecessor(TreeNode *root)
    {
        root = root->left;
        while (root->right != nullptr)
            root = root->right;
        return root->val;
    }

    // TODO:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        // 从右子树删除
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        // 从左子树删除
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            // 从目前结点删除
            // 该结点是叶子结点
            if (root->left == nullptr && root->right == nullptr)
                root == nullptr;
            else if (root->right != nullptr)
            {
                // 该结点不是叶子结点，且有右子树
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else
            {
                // 该结点不是叶子结点，有左子树
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }

        return root;
    }
};

int main()
{
}