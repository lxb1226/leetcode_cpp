#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        vector<int> ans;

        // while(i < m && j < n){
        //     // 判定往那边走
        //     if(j == n - 1 && i != m - 1){
        //         // 往下走

        //     }else if(j == n - 1 && i == m - 1){
        //         // 往左走

        //     }else if(j == 0 && ){

        //     }

        //     ans.push_back(matrix[i][j]);
        //     if(j == n - 1){

        //     }
        // }
    }
};

int main(){

}