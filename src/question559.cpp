#include <iostream>
#include <vector>
 
using namespace std;

class Node{
    public:
    int val;
    vector<Node*> children;

    Node(){}

    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int max_depth;
    int maxDepth(Node* root) {
        max_depth = 0;
        dfs(root, 0);
        return max_depth;
    }

    void dfs(Node* root, int depth){
        if(root == nullptr){
            max_depth = max(max_depth, depth);
            cout << max_depth << endl;
            return;
        }
        for(Node* node : root->children){
            dfs(node, depth + 1);
        }
    }
};
 
int main(){
    
 
}