#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    // 法一：递归求解
    int maxDepth(TreeNode* root) {
        int depth = 0, max_depth = 0;
        dfs(root, depth, max_depth);
        return max_depth;
    }

    void dfs(TreeNode* node, int depth, int& max_depth){
        if(!node){
            max_depth = max(depth, max_depth);
            return;
        }
        dfs(node->left, depth + 1, max_depth);
        dfs(node->right, depth + 1, max_depth);
    }

    // 法二：迭代求解
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while(!Q.empty()){
            int sz = Q.size();
            while (sz > 0)
            {
                TreeNode* node = Q.front(); Q.pop();
                if(node->left) Q.push(node->left);
                if(node->right) Q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        }

        return ans;
    }
};

int main(){

}