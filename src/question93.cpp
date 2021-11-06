#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> tmp;
    int n;
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        backtrack(s, 0);
        return ans;
    }

    void backtrack(string s,int idx){
        if(idx == n){
            string str;
            for(int i = 0; i < tmp.size(); ++i){
                str += tmp[i];
                if(i < tmp.size() - 1){
                    str += '.';
                }
            }
            ans.push_back(str);
            return;
        }
        int cnt = min(idx + 3, n);
        for(int j = idx; j < cnt; ++j){
            if(isValid(s, idx, j)){
                tmp.push_back(s.substr(idx, j - idx + 1));
                backtrack(s, j + 1);
                tmp.pop_back();
            }
        }
    }

    bool isValid(string s, int i, int j){
        if(s[i] == '0' && i != j){
            return false;
        }else if(i == j){
            return true;
        }
        int num = 0;
        for(int m = j; m >= i; m--){
            num = num * 10 + s[m] - '0';
        }
        if(num <= 255){
            return true;
        }else{
            return false;
        }
    }
};

int main(){

}