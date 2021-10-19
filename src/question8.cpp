#include <iostream>
#include <vector>
#include <stdlib.h>
#include <climits>
#include <unordered_map>

using namespace std;

class Automaton{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end","end","end","end"}}
    };

    int get_col(char c){
        if(isspace(c)) return 0;
        if(c == '+' or c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c){
        state = table[state][get_col(c)];
        if(state == "in_number"){
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }else if(state == "signed"){
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution {
public:
    int myAtoi(string s){
        Automaton automaton;
        for(char c : s){
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }

    int myAtoi1(string s) {
        int len = s.length();
        int i = 0;
        int sign = 1; // true表示为正，false表示为负
        // 先找到前导空格
        while(i < len && s[i] == ' '){
            i++;
        }
        // 判断当前i是否是负号还是啥
        if(s[i] == '+'){
            sign = 1;
            i++;
        }else if(s[i] == '-'){
            sign = -1;
            i++;
        }
        
        int res = 0;
        
        while(i < len){
            if(!isdigit(s[i])){
                // 如果是字母，需要判断其是不是第一个
                break;
            }else{
                // 如果是数字,那么加起来
                int num = s[i] - '0';
                // 还需要判断res是否超出了32位有符号整数范围
                if(res > INT_MAX / 10 || res == INT_MAX / 10 && num > 7)
                    return INT_MAX;
                if(res < INT_MIN / 10 || (res == INT_MIN / 10 && -num < INT_MIN % 10))
                    return INT_MIN;
                
                res = res * 10 + sign * num;
                
            }
            i++;
        }

        return res;
    }
};

int main(){
    // string s = "    -42";
    // string s = "4193 with words";
    // string s = "words and 987";
    string s = "-91283472332";
    Solution su;
    auto ans = su.myAtoi(s);

    cout << ans << endl;
}