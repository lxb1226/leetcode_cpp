#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 双指针只需要遍历一遍,更多的是考虑边界条件
    // 需要考虑倒数第一个和第一个
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p, *q;
        p = q = head;

        for(int i = 0; i < n; i++)
            p = p->next;
        if(!p){
            // 如果p为空，那么则删除第一个。
            return q->next;
        }
        
        while(p->next){
            p = p->next;
            q = q->next;
        }

        // 如果是倒数第一个
        if(n == 1){
            q->next = nullptr;
        }else{
            q->next = q->next->next;
        }
        return head;
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
    // vector<int> nums{1, 2, 3, 4, 5};
    vector<int> nums{1, 2};
    int n = 2;
    ListNode* head = new ListNode();
    buildList(nums, head);

    Solution s;
    head = s.removeNthFromEnd(head->next, n);

    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;

}