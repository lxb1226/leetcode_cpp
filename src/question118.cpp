#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if(numRows == 1)
            return res;
        for(int i = 1; i < numRows; i++){
            vector<int> tmp(i + 1);
            for(int j = 0; j <= i; j++){
                if(j == 0)
                    tmp[j] = 1;
                else if(j == i)
                    tmp[j] = 1;
                else
                    tmp[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(tmp);
        }

        return res;
    }
};

int main(){
    int numRows = 1;
    Solution solution;
    auto res = solution.generate(numRows);
    for(auto tmp : res){
        for(auto num : tmp){
            cout << " " << num;
        }
        cout << endl;
    }
}