#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    // 两指针法 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* pA = headA;
        ListNode* pB = headB;

        while(pA != nullptr && pB != nullptr){
            pA = pA->next;
            pB = pB->next;
        }

        if(!pA && pB){
            // pA为null，pB不为null
            while(headB && pB){
                headB = headB->next;
                pB = pB->next;
            }
        }else if(pA && !pB){
            // pB为null，pA不为null
            while(headA && pA){
                headA = headA->next;
                pA = pA->next;
            }
        }

        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;

    }
};

int main(){

}