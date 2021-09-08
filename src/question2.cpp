#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // TODO:不想写
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root, *p;
        p = root;
        bool flag = false;
        while(l1 && l2){
            int sum = l1->val + l2->val + (int)flag;
            ListNode *tmp;
            if(sum >= 10){
                // sum大于10
                tmp->val = sum % 10;
                flag = true;
            }else{
                // sum小于10
                tmp->val = sum;
                flag = false;
            }
            p->next = tmp;
            p = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }
        // 判断是谁长，并将其指向l1.
        if(!l1) l1 = l2;
        p->next = l1;
        
        // 判断最后是否要加1，要遍历后面的列表
        while(l1){
            if(l1->val + (int)flag == 10){
                l1->val = 0;
                p = l1;
                l1 = l1->next;
            }else{
                flag = false;
                break;
            }
        }
        ListNode* tmp;
        if(flag){
            tmp->val = 1;
            p->next = tmp;
        }
        
        return root->next;
    }
};

int main(){
    ListNode *l1, *l2;
    l1->val = 5;
    
    vector<int> nums1{2, 4, 3}, nums2{5, 6, 4};
    
}