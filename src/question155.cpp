#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <queue>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        x_stk.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        x_stk.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stk.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> x_stk;
    stack<int> min_stack;
};

int main(){

}