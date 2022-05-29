#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    // 法二：不利用其他空间
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int flag = 0;
        ListNode *p = l1;
        ListNode *pre = nullptr;
        ListNode *head = p;
        while (l1 && l2)
        {
            int val = l1->val + l2->val + flag;
            flag = val / 10;
            val = val % 10;
            p->val = val;
            l1 = l1->next;
            l2 = l2->next;
            pre = p;
            p = p->next;
        }
        if (l1 == nullptr)
        {
            l1 = l2;
            p = l2;
            pre->next = l2;
        }
        while (l1)
        {
            int val = l1->val + flag;
            flag = val / 10;
            val = val % 10;
            p->val = val;
            l1 = l1->next;
            pre = p;
            p = p->next;
        }
        if (flag == 1)
        {
            ListNode *tmp = new ListNode(1);
            pre->next = tmp;
        }
        return head;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        int flag = 0;
        ListNode *l3 = dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            int val = l1->val + l2->val + flag;
            if (val / 10 == 1)
            {
                flag = 1;
                val = val % 10;
            }
            else
            {
                flag = 0;
            }
            ListNode *tmp = new ListNode(val);
            l3->next = tmp;
            l3 = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }
        l1 = l1 == nullptr ? l2 : l1;
        while (l1 != nullptr)
        {
            int val = l1->val + flag;
            if (val / 10 == 1)
            {
                flag = 1;
                val = val % 10;
            }
            else
            {
                flag = 0;
            }
            ListNode *tmp = new ListNode(val);
            l3->next = tmp;
            l3 = tmp;
            l1 = l1->next;
        }

        if (flag == 1)
        {
            ListNode *tmp = new ListNode(1);
            l3->next = tmp;
        }

        return dummy->next;
    }
};

int main()
{
}