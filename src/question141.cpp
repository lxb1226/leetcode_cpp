#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    // 快慢指针
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

ListNode* buildList(vector<int>& nums){
    ListNode* dummy = new ListNode(0);
    for(auto num : nums){
        ListNode* tmp = new ListNode(num);
        dummy->next = tmp;
        dummy = tmp;
    }
    return dummy->next;

}

int main(){
    vector<int> nums{3, 2, 0, -4};
    Solution su;
    ListNode* root = buildList(nums);
    auto ans = su.hasCycle(root);
    cout << ans << endl;
}