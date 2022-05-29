#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* p1 = head, *p2 = dummy;
        for(int i = 0; i < n; ++i){
            p1 = p1->next;
        }
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return dummy->next;
    }
};

int main()
{
}