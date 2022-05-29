#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution {
public:

    // 法一：递归
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }else if(list2 == nullptr){
            return list1;
        }else if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    // 法二：迭代
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(list1 && list2){
            if(list1->val < list2->val){
                p->next = list1;
                list1 = list1->next;
            }else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        list1 = list1 == nullptr ? list2 : list1;
        p->next = list1;
        return dummy->next;
    }
};

int main()
{
}