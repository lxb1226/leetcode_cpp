#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



struct cmp{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 构建一个最小堆队列，首先将每个列表的头指针放到里面去
        priority_queue<ListNode*, vector<ListNode*> ,cmp> min_queue;
        for(ListNode* item : lists){
            min_queue.push(item);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        ListNode* tmp;
        while(!min_queue.empty()){
            tmp = min_queue.top();
            min_queue.pop();
            if(tmp->next != nullptr){
                min_queue.push(tmp->next);
            }
            head->next = tmp;
            tmp->next = nullptr;
            head = tmp;
        }
        return dummy->next;
    }
};

int main(){

}