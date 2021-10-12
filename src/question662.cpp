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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int max_width = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int l = -1, r = -1;
            bool is_first = true;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                if(root != nullptr){
                    if(is_first){
                        l = i;
                        r = i;
                        is_first = false;
                    }else{
                        r = i;
                    }
                    q.push(root->left);
                    q.push(root->right);
                }else{
                    q.push(root->left);
                    q.push(root->right);
                }
            }

            if(l == -1 && r == -1){
                break;
            }

            max_width = max(max_width, r - l + 1);
        }
        return max_width;

    }
};

int main(){

}