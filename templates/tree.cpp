#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

/**
 * 二叉树相关算法实现：
 * 
 */

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

// 先序遍历，非递归版本 中左右
void pre_traversal(TreeNode *root)
{
    stack<TreeNode *> node_stack;

    while (root != nullptr || !node_stack.empty())
    {
        if (root != nullptr)
        {
            cout << root->val << " ";
            node_stack.push(root);
            root = root->left;
        }
        else
        {
            root = node_stack.top();
            node_stack.pop();
            root = root->right;
        }
    }
}

// 中序遍历, 非递归版本 左中右
void in_traversal(TreeNode *root)
{
    stack<TreeNode *> stack_node;
    while (root != nullptr || !stack_node.empty())
    {
        if (root != nullptr)
        {
            stack_node.push(root);
            root = root->left;
        }
        else
        {
            root = stack_node.top();
            cout << root->val << " ";
            stack_node.pop();
            root = root->right;
        }
    }
}

// 后序遍历，非递归版本 左右中
void post_traversal(TreeNode *root)
{
    stack<TreeNode *> stack_node;
    TreeNode *lastvisit = root;
    while (root != nullptr || !stack_node.empty())
    {
        if (root != nullptr)
        {
            stack_node.push(root);
            root = root->left;
        }
        else
        {
            root = stack_node.top();
            if (root->right == nullptr || root->right == lastvisit)
            {
                cout << root->val << " ";
                stack_node.pop();
                lastvisit = root;
                root = nullptr;
            }
            else
            {
                root = root->right;
            }
        }
    }
}

// 层序遍历
void level_order(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root != nullptr)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        TreeNode *node = q.front();
        cout << node->val << " ";
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
        q.pop();
    }
}

// 创建一棵二叉树
TreeNode *createTree()
{
    TreeNode *A = new TreeNode(1);
    TreeNode *B = new TreeNode(2);
    TreeNode *C = new TreeNode(4);
    TreeNode *D = new TreeNode(7);
    TreeNode *E = new TreeNode(3);
    TreeNode *F = new TreeNode(5);
    TreeNode *G = new TreeNode(6);
    TreeNode *H = new TreeNode(8);

    A->left = B;
    A->right = E;
    B->left = C;
    C->right = D;
    E->left = F;
    E->right = G;
    G->left = H;

    return A;
}

int main()
{
    TreeNode *root = createTree();

    cout << "pre traversal : " << endl;
    pre_traversal(root);
    cout << endl;

    cout << "inorder traversal : " << endl;
    in_traversal(root);
    cout << endl;

    cout << "post traversal : " << endl;
    post_traversal(root);
    cout << endl;

    cout << "level travelsal : " << endl;
    level_order(root);
    cout << endl;
}
