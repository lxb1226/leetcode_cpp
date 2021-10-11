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

class Solution {
private:
    int max_depth = 0;
    int val = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 1);
        return val;
    }

    void dfs(TreeNode* root, int depth){
        if(root->left == nullptr){
            if(depth > max_depth){
                max_depth = depth;
                val = root->val;
            }
        }else{
            dfs(root->left, depth+1);
        }

        if(root->right != nullptr){
            dfs(root->right, depth+1);
        }

    }
};

int main(){

}