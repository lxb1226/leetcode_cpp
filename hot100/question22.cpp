#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution {
public:
    vector<string> res;
    string curr;

    void backtrack(int open, int close, int n){
        if(open == n && close == n){
            res.push_back(curr);
            return;
        }
        if(open > n || close > n || open < close){
            return;
        }
        
        curr.push_back('(');
        backtrack(open + 1, close, n);
        curr.pop_back();

        if(open > close){
            curr.push_back(')');
            backtrack(open, close + 1, n);
            curr.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, n);
        return res;
    }
};

int main()
{
}