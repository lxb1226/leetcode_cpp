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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return restructTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size());
    }

    TreeNode *restructTree(vector<int> &preorder, vector<int> &inorder, int left_p, int right_p, int left_i, int right_i)
    {
        if (left_p > right_p)
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(preorder[left_p]);
        int pos;
        for (pos = left_i; pos <= right_i; ++pos)
        {
            if (inorder[pos] == preorder[left_p])
            {
                break;
            }
        }
        node->left = restructTree(preorder, inorder, left_p + 1, pos - left_i + left_p, left_i, pos - 1);
        node->right = restructTree(preorder, inorder, pos - left_i + left_p + 1, right_p, pos + 1, right_i);
        return node;
    }
};

int main()
{
}