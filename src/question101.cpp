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
    // 法一：递归
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    
    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    // 法二：迭代
    bool check(TreeNode* u, TreeNode* v){
        queue<TreeNode*> q;
        q.push(u);
        q.push(v);

        while(!q.empty()){
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if(!u && !v) continue;
            if((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }

        return true;
    }


};

int main(){

}