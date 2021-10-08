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
    // TODO: 
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 1.首先查找到key的位置，找到后查找下一个位置，如何查找？
        TreeNode* delete_node = findNode(root, key);
        TreeNode* left_node;
        if(delete_node->right != nullptr){
            // 查找右子树中最左边的那个节点
            left_node = delete_node->right;
            while(left_node->left){
                left_node = left_node->left;
            }
            
        }else{
            // 直接删除

        }

    }

    TreeNode *findNode(TreeNode* root, int key){
        if(root->val == key){
            return root;
        }else if(root->val > key){
            return findNode(root->left, key);
        }else{
            return findNode(root->right, key);
        }
    }
};

int main()
{
}