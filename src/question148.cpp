#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){} 
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    // 二分法，双指针
    ListNode* sortList(ListNode* head) {
        
    }
};

int main(){

}