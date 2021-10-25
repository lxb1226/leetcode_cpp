#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equals(vector<int>& sCnt, vector<int>& pCnt){
        for(int i = 0; i < sCnt.size(); i++){
            if(sCnt[i] != pCnt[i]){
                return false;
            }
        }
        return true;
    }

    // TODO:有bug
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        if(n < m) return vector<int>{};
        vector<int> pCnt{26, 0};
        vector<int> sCnt{26, 0};
        for(int i = 0; i < m; i++){
            pCnt[p[i] - 'a']++;
            sCnt[s[i] - 'a']++;
        }
        // 判断两个数组是否相等
        if(equals(sCnt, pCnt)){
            res.push_back(0);
        }
        
        for(int i = m; i < n; i++){
            sCnt[s[i - m] - 'a']--;
            sCnt[s[i] - 'a']++;
            if(equals(sCnt, pCnt)){
                res.push_back(i - m + 1);
            }
        }

        return res;
    }
};

int main(){
    string s = "cbaebabacd", p = "abc";
    Solution su;
    auto ans = su.findAnagrams(s, p);
    for(auto& num : ans){
        cout << num << " ";
    }
    cout << endl;
}