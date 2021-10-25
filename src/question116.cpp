#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;
        helper(root, nullptr);
        return root;
    }

    void helper(Node *node, Node *next_node)
    {

        if (node->left == nullptr && node->right == nullptr)
            return;
        node->left->next = node->right;
        Node *left_node = nullptr;
        if (next_node != nullptr)
            left_node = next_node->left;

        node->right->next = left_node;
        helper(node->left, node->right);
        helper(node->right, left_node);
    }
};

int main()
{
}