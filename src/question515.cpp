#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();

            int max_val = INT_MIN;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                if(root->val > max_val){
                    max_val = root->val;
                }
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            ans.push_back(max_val);
        }

        return ans;
    }
};

int main(){

}