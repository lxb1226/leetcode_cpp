#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1){
            return l2;
        }

        if(!l2){
            return l1;
        }

        ListNode* head = new ListNode();
        ListNode* p = head;
        // 每次取最小值
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        while(!l1){
            l1 = l2;
        }
        p->next = l1;

        return head->next;
    }
};

ListNode* build_list(vector<int> nums){
    ListNode* head = new ListNode();
    ListNode* p = head;
    for(auto num : nums){
        ListNode* tmp = new ListNode(num);
        p->next = tmp;
        p = p->next;
    }
    return head->next;
}

int main(){
    vector<int> nums1{1, 2, 4}, nums2{1, 3, 4};
    ListNode* l1 = build_list(nums1);
    ListNode* l2 = build_list(nums2);
    Solution su;
    ListNode* ans = su.mergeTwoLists(l1, l2);
    while(ans){
        cout << ans->val << endl;
        ans = ans->next;
    }
}