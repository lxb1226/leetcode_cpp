#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n, true));

        for(int i = n - 1; i >= 0; --i){
            for(int j = i + 1; j < n; ++j){
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        dfs(s, 0);
        return ret;
    }

    void dfs(const string& s, int i){
        if(i == n){
            ret.push_back(ans);
            return;
        }
        for(int j = i; j < n; ++j){
            if(f[i][j]){
                ans.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }    
};

int main(){
    string str = "aab";
    Solution su;
    auto ans = su.partition(str);
    for(auto strs : ans){
        for(auto str : strs){
            cout << str << " ";
        }
        cout << endl;
    }
}