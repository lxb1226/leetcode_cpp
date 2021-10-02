#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> queue_;

        queue_.push(root);

        while (root != nullptr && !queue_.empty())
        {
            vector<int> tmp;
            auto size = queue_.size();
            while (size > 0)
            {

                root = queue_.front();
                queue_.pop();
                if (root->left)
                    queue_.push(root->left);
                if (root->right)
                    queue_.push(root->right);

                tmp.push_back(root->val);
                size--;
            }

            ans.insert(ans.begin(), tmp);
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
    auto ans = su.levelOrderBottom(root);
    for (auto nums : ans)
    {
        for (auto num : nums)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}