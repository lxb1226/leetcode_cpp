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

        ListNode* p;
        if(pA == nullptr && pB != nullptr){
            p = headB;
            pA = headA;
            while(pB != nullptr){
                pB = pB->next;
                p = p->next;
            }
            while(p && pA){
                if(p == pA){
                    return p;
                }
                p = p->next;
                pA = pA->next;
            }
        }else if(pA != nullptr && pB == nullptr){
            p = headA;
            pB = headB;
            while(pA){
                pA = pA->next;
                p = p->next;
            }
            while(p && pB){
                if(p == pB){
                    return p;
                }
                p = p->next;
                pA = pA->next;
            }
        }else{
            pA = headA;
            pB = headB;
            while(pA && pB){
                if(pA == pB){
                    return pA;
                }
                pA = pA->next;
                pB = pB->next;
            }
        }

        return nullptr;
    }
};

int main(){

}