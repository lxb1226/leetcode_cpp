#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char, string> m{make_pair('2', "abc"), make_pair('3', "def"), 
        make_pair('4', "ghi"), make_pair('5', "jkl"), make_pair('6', "mno"),
        make_pair('7', "pqrs"), make_pair('8', "tuv"), make_pair('9', "wxyz")};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        string s;
        dfs(digits, s, ans);
        return ans;
    }    

    void dfs(string digits, string s, vector<string>& ans){
        if(digits.size() == 0){
            ans.push_back(s);
        }

        string letters = m[digits[0]];
        for(auto letter : letters){
            s += letter;
            dfs(digits.substr(1, digits.size() - 1), s, ans);
            // 回退的操作
            s = s.substr(0, s.size() - 1);
        }
    }


};

int main(){
    string digits = "";
    Solution s;
    auto ans = s.letterCombinations(digits);
    for(auto str : ans){
        cout << str << endl;
    }
}