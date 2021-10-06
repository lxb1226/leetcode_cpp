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
    // TODO: 仔细想想
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 1.首先查找到key的位置，然后再去查找到key的下一个的位置
    }
};

int main()
{
}