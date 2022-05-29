#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        auto cmp = [](ListNode* list1, ListNode* list2){return list1->val > list2->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] != nullptr)
                q.push(lists[i]);
        }
        while(!q.empty()){
            ListNode* tmp = q.top();
            q.pop();
            head->next = tmp;
            head = head->next;
            if(tmp->next != nullptr){
                q.push(tmp->next);
            }
        }

        return dummy->next;
    }
};

int main()
{
}