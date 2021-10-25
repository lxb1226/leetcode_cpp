#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

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
    typedef tuple<TreeNode*,long,long> Node;
    int widthOfBinaryTree(TreeNode* root) {
        queue<Node> q;
        int cur_depth = 0, left = 0, ans = 0;
        q.push(make_tuple(root, 0, 0));
        while(!q.empty()){
            Node node = q.front();
            q.pop();
            root = std::get<0>(node);
            int depth = std::get<1>(node);
            int pos = std::get<2>(node);
            if(root){
                q.push(make_tuple(root->left, depth + 1, pos * 2));
                q.push(make_tuple(root->right, depth + 1, pos * 2 + 1));
                
                if(cur_depth != depth){
                    cur_depth = depth;
                    left = pos;
                }

                ans = max(pos - left + 1, ans);
            }

        }

        return ans;
    }

    // 超时
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