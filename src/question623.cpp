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

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            // 新建一个节点
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        queue<TreeNode*> q;
        TreeNode* tmp = root;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            depth--;
            if(depth == 1){
                // 到了d-1层了
                for(int i = 0; i < size; i++){
                    root = q.front();
                    q.pop();
                    TreeNode* left_node = new TreeNode(val);
                    TreeNode* right_node = new TreeNode(val);
                    left_node->left = root->left;
                    root->left = left_node;
                    right_node->right = root->right;
                    root->right = right_node;
                }
                break;
            }else{
                for(int i = 0; i < size; i++){
                    root = q.front();
                    q.pop();
                    if(root->left) q.push(root->left);
                    if(root->right) q.push(root->right);
                }
            }

            
        }

        return root;
    }
};

int main(){

}