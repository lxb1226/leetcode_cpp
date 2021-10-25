#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // TODO:快慢指针
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr){
                return nullptr;
            }

            fast = fast->next->next;
            if(fast == slow){
                ListNode *ptr = head;
                while(ptr != slow){
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

int main(){

}