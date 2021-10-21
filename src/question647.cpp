#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力法通过
    bool isHui(string& tmp){
        int i = 0, j = tmp.size() - 1;
        while(i < j){
            if(tmp[i++] != tmp[j--]) return false;
        }
        return true;
    }
    
    // 一、暴力法
    int countSubstrings1(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 1; j <= s.size() - i; ++j){
                string tmp = s.substr(i, j);
                // cout << tmp << endl;
                if(isHui(tmp)) cnt++;
            }
        }

        return cnt;
    }

    // 二、中间拓展
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < 2 * n - 1; ++i){
            int l = i / 2, r = i / 2 + i % 2;
            while(l >= 0 && r < n && s[l] == s[r]){
                --l;
                ++r;
                ++ans;
            }
        }

        return ans;
    }

    // 三、Manacher 算法
};

int main(){
    string s = "aaa";
    Solution su;
    auto ans = su.countSubstrings(s);
    cout << ans << endl;
}