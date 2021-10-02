#include <iostream>
#include <vector>
#include <deque>

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
    // TODO:层次遍历再加上一个标记用来判断奇偶
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        deque<TreeNode *> queue_;

        queue_.push_back(root);
        int level = 1;
        while (root != nullptr && !queue_.empty())
        {
            vector<int> tmp;
            auto size = queue_.size();
            while (size > 0)
            {
                if (level % 2 == 1)
                {
                    root = queue_.front();
                    queue_.pop_front();
                    if (root->left)
                        queue_.push_back(root->left);
                    if (root->right)
                        queue_.push_back(root->right);
                }
                else
                {
                    root = queue_.back();
                    queue_.pop_back();
                    if (root->right)
                        queue_.push_front(root->right);
                    if (root->left)
                        queue_.push_front(root->left);
                }
                tmp.push_back(root->val);
                size--;
            }
            level += 1;
            ans.push_back(tmp);
        }

        return ans;
    }
};

TreeNode *buildTree()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

int main()
{
    TreeNode *root = buildTree();
    Solution su;
    auto ans = su.zigzagLevelOrder(root);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}