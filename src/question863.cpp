#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;

    void findParents(TreeNode* node){
        if(node->left != nullptr){
            parents[node->left->val] = node;
            findParents(node->left);
        }
        if(node->right != nullptr){
            parents[node->right->val] = node;
            findParents(node->right);
        }
    }

    void findAns(TreeNode* node, TreeNode* from, int depth, int k){
        if(node == nullptr){
            return;
        }

        if(depth == k){
            ans.push_back(node->val);
            return;
        }

        if(node->left != from){
            findAns(node->left, node, depth + 1, k);
        }

        if(node->right != from){
            findAns(node->right, node, depth + 1, k);
        }

        if(parents[node->val] != from){
            findAns(parents[node->val], node, depth + 1, k);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root);

        findAns(target, nullptr, 0, k);

        return ans;
    }


};

int main(){

}