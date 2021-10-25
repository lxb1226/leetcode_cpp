#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // 这题就是栈的应用，主要的难点在于测试用例的构建，需要注意边界条件
    bool isValid(string s) {
        stack<char> brackets;
        bool flag = false;
        for(auto& c : s){
            switch (c)
            {
            case '[':
                brackets.push(c);
                break;
            case '(':
                brackets.push(c);
                break;
            case '{':
                brackets.push(c);
                break;
            case ')':{
                if(brackets.size() == 0 || brackets.top() != '('){
                    return false;
                }else{
                    brackets.pop();
                }
                break;
            }
            case ']':{
                if(brackets.size() == 0 || brackets.top() != '['){
                    return false;
                }else{
                    brackets.pop();
                }
                break;
            }
            case '}':{
                if(brackets.size() == 0 || brackets.top() != '{'){
                    return false;
                }else{
                    brackets.pop();
                }
                break;
            }
            }
        }

        if(brackets.size() == 0){
            return true;
        }
        return false;
    }
};

int main(){
    // string s = "()";
    string s = "([)]";
    Solution su;
    auto ans = su.isValid(s);
    cout << ans << endl;
}