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
    // TODO:位运算+二分查找
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int level = 0;
        TreeNode *node = root;
        // 计算完全二叉树的高度
        while (node->left != nullptr)
        {
            level++;
            node = node->left;
        }
        // 计算最后一层最少以及最多的个数
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        // 二分查找 左闭右开
        while (low < high)
        {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode *root, int level, int k)
    {
        int bits = 1 << (level - 1);
        TreeNode *node = root;
        while (node != nullptr && bits > 0)
        {
            if (!(bits & k)) // 比较最后一位比特位
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
            bits >>= 1;
        }

        return node != nullptr;
    }
};

int main()
{
}