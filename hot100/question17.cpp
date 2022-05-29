#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;
class Solution {
public:
    vector<string> chars{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;
    void backtracker(string digits, int idx){
        if(idx == digits.size()){
            ans.push_back(path);
            return;
        }
        int num = digits[idx] - '0' - 2;
        for(auto &c : chars[num]){
            path.push_back(c);
            backtracker(digits, idx + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};
        backtracker(digits, 0);
        return ans;
    }
};

int main()
{
}