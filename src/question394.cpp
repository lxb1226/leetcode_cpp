#include <iostream>
#include <vector>
#include <unistd.h>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans;
        
        stack<int> cnts;
        stack<string> strs;
        int cnt = 0;
        string tmp;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '['){
                tmp.clear();
                continue;
            }else if(s[i] == ']'){
                // 做一个出栈的处理
                strs.push(tmp);
                cnt = cnts.top();
                tmp = strs.top();
                cnts.pop();
                strs.pop();
                for(int j = 0; j < cnt; j++){
                    ans += tmp;
                }
            }else if(isdigit(s[i])){
                // 如果遇到了数字，那么把之前的字符串放进去
                strs.push(tmp);

                
                cnts.push(s[i] - '0');
            }else{
                // 字母,需要进一步考虑
                tmp += s[i];
            }
        }

        return ans;
    }
};

int main(){
    string str = "3[a]2[bc]";
    Solution su;
    auto ans = su.decodeString(str);
    cout << ans << endl;
}