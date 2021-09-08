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
    // 代码逻辑感人，算法不难，就是不想写。好在通过了
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* p = root;
        int flag = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + flag;
            ListNode *tmp = new ListNode();
            if(sum >= 10){
                // sum大于10
                tmp->val = sum % 10;
                flag = 1;
            }else{
                // sum小于10
                tmp->val = sum;
                flag = 0;
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
            if(l1->val + flag == 10){
                l1->val = 0;
                p = l1;
                l1 = l1->next;
            }else{
                l1->val = l1->val + flag;
                flag = 0;
                break;
            }
        }
        ListNode* tmp = new ListNode();
        if(flag){
            tmp->val = 1;
            p->next = tmp;
        }
        
        return root->next;
    }
};

void buildList(vector<int>& nums, ListNode* root){
    for(auto num : nums){
        ListNode* tmp = new ListNode();
        tmp->val = num;
        root->next = tmp;
        root = tmp;
    }
}


int main(){
    ListNode *l1 = new ListNode();
    ListNode *l2 = new ListNode();
    
    
    // vector<int> nums1{2, 4, 3}, nums2{5, 6, 4};
    vector<int> nums1{9,9,9,9,9,9,9}, nums2{9, 9, 9, 9};
    buildList(nums1, l1);
    buildList(nums2, l2);


    Solution s;
    ListNode* root = s.addTwoNumbers(l1->next, l2->next);

    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    
}