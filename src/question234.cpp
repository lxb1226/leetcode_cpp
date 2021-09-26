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
    // TODO:思路基本一致
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        // 考虑链表为奇数，以及为偶数的情况
        // 如果fast为最后一个，就是奇数，否则为偶数
        if(!fast->next){
            // 奇数

        }else{
            // 偶数

        }

        // 翻转链表


    }
};

int main(){

}