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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* getMedian(ListNode* left, ListNode* right){
        ListNode* fast = left;
        ListNode* slow = left;
        while(fast != right && fast->next != right){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // TODO:思路一致 具体细节上没有考虑清楚
    // 首先找到链表的中间结点作为头结点，中间结点的左边链表作为中间结点的左子树，右边链表作为中间结点的右子树
    TreeNode *sortedListToBST(ListNode *head)
    {
        return buildTree(head, nullptr);
    }

    TreeNode* buildTree(ListNode* left, ListNode* right){
        if(left == right)
            return nullptr;
        
        ListNode* mid = getMedian(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(left, mid);
        root->right = buildTree(mid->next, right);
        return root;
    }
};

ListNode *buildList(vector<int> &nums)
{
    ListNode *head = new ListNode();
    ListNode *dummy = head;
    for (auto &num : nums)
    {
        ListNode *tmp = new ListNode(num);
        dummy->next = tmp;
        dummy = dummy->next;
    }
    return head->next;
}

void printTree(TreeNode *root)
{
    if (root)
    {
        cout << " " << root->val;
        printTree(root->left);
        printTree(root->right);
    }
}

void printList(ListNode *head)
{
    ListNode *tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> nums{-10, -3, 0, 5, 9};
    ListNode *head = buildList(nums);

    Solution su;
    auto ans = su.sortedListToBST(head);
    printTree(ans);
}