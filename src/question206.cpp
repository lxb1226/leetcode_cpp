#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* dummy = new ListNode();

        ListNode* p = head->next;
        while(head){
            head->next = dummy->next;
            dummy->next = head;
            head = p;
            if(p)
                p = head->next;
        }
        return dummy->next;
    }
};

ListNode* buildList(vector<int>& nums){
    ListNode* head = new ListNode();
    ListNode* p = head;
    for(auto num : nums){
        ListNode* tmp = new ListNode(num);
        head->next = tmp;
        head = head->next;
    }
    return p->next;
}

int main(){
    vector<int> nums{1, 2, 3, 4, 5};
    Solution su;
    ListNode* head = buildList(nums);
    head = su.reverseList(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}