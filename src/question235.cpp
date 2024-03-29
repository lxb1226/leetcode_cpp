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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true)
        {
            if(p->val < ancestor->val && q->val < ancestor->val){
                ancestor = ancestor->left;
            }else if(p->val > ancestor->val && q->val > ancestor->val){
                ancestor = ancestor->right;
            }else{
                break;
            }

        }
        return ancestor;
    }
};

int main(){

}