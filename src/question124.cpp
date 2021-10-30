#include <iostream>
#include <vector>
#include <climits>

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
    int ans = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        travel(root);
        return ans;
    }

    int maxGain(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        int priceNewpath = node->val + leftGain + rightGain;
        ans = max(ans, priceNewpath);
        return node->val + max(leftGain, rightGain);
    }

    // 还是没有考虑清楚 代码太复杂了
    int travel(TreeNode *root)
    {
        int max_l, max_r, max_val;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans = max(ans, root->val);
            return root->val;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            max_r = travel(root->right);

            max_val = max(root->val, max_r + root->val);
            // 右子树不包括根节点，右子树包括根节点，只有根节点
            ans = max(max(ans, max_r), max_val);
        }
        else if (root->right == nullptr && root->left != nullptr)
        {
            max_l = travel(root->left);
            max_val = max(root->val, max_l + root->val);
            ans = max(max(ans, max_l), max_val);
        }
        else
        {
            max_l = travel(root->left);
            max_r = travel(root->right);
            max_val = max(max(max_l, max_r) + root->val, root->val);
            // 最大值可能的路径， 左子树不包括根节点，右子树不包括根节点，左子树包括根节点，右子树包括根节点，三者都有，只有根节点
            ans = max(max(ans, max_val), max(max_l, max_r));
            ans = max(ans, max_l + max_r + root->val);
        }

        return max_val;
    }
};

int main()
{
}