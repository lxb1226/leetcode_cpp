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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        

        // 无论是奇数还是偶数，都是翻转slow->next
        // 翻转链表
        fast = reverseList(slow->next);
        while(head && fast){
            if(head->val != fast->val){
                return false;
            }
            head = head->next;
            fast = fast->next;
        }
        
        return true;

    }

    ListNode* reverseList(ListNode* root){
        ListNode* dummy = new ListNode();
        ListNode* next = root->next;
        while(next){
            root->next = dummy->next;
            dummy->next = root;
            root = next;
            next = root->next;
        }
        root->next = dummy->next;
        dummy->next = root;
        return dummy->next;
    }
};

ListNode* buildList(vector<int>& nums){
    ListNode* dummy = new ListNode();
    ListNode* head = dummy;
    for(auto& num : nums){
        ListNode* node = new ListNode(num);
        head->next = node;
        head = head->next;
    }
    return dummy->next;
}

int main(){
    vector<int> nums{1, 2};
    ListNode* root = buildList(nums);
    Solution su;
    auto ans = su.isPalindrome(root);
    cout << ans << endl;
}