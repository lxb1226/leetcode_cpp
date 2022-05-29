#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                    stk.push(c);
                    break;
                case ')':
                    if(stk.empty())
                        return false;
                    c = stk.top();
                    stk.pop();
                    if(c != '('){
                        return false;
                    }
                    break;
                case ']':
                    if(stk.empty())
                        return false;
                    c = stk.top();
                    stk.pop();
                    if(c != '['){
                        return false;
                    }
                    break;
                case '}':
                    if(stk.empty())
                        return false;
                    c = stk.top();
                    stk.pop();
                    if(c != '{'){
                        return false;
                    }
                    break;
            }
        }
        if(!stk.empty())
            return false;

        return true;
    }
};

int main()
{
}