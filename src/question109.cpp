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
    // TODO:有bug
    // 首先找到链表的中间结点作为头结点，中间结点的左边链表作为中间结点的左子树，右边链表作为中间结点的右子树
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head)
            return nullptr;
        TreeNode *root = new TreeNode();
        ListNode *slow = head, *fast = head;
        // 找到链表的中间结点
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        root->val = slow->next->val;
        root->right = sortedListToBST(slow->next);
        slow->next = nullptr;
        root->left = sortedListToBST(head);

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

int main()
{
    vector<int> nums{-10, -3, 0, 5, 9};
    ListNode *head = buildList(nums);
    Solution su;
    auto ans = su.sortedListToBST(head);
    printTree(ans);
}