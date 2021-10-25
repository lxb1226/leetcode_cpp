#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;
        vector<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        int cur_cnt = 1;
        int next_cnt = 0;
        while(q.size() != 0){
            TreeNode* p = q.front();
            if(p != nullptr){
                q.pop();
                tmp.push_back(p->val);
                cur_cnt--;
            }

            if(p->left != nullptr){
                q.push(p->left);
                next_cnt++;
            }

            if(p->right != nullptr){
                q.push(p->right);
                next_cnt++;
            }

            if(cur_cnt == 0){
                ans.push_back(tmp);
                tmp.clear();
                cur_cnt = next_cnt;
                next_cnt = 0;
            }
        }
        
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    auto ans = s.levelOrder(root);
    for(auto nums : ans){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
}