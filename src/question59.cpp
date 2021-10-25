#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        // 顺序：右，下，左，上
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxNum = n * n;
        int curNum = 1;
        int directionIndex = 0;
        int row = 0, column = 0;
        while(curNum <= maxNum){
            matrix[row][column] = curNum;
            curNum++;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if(nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0){
                directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
            }
            row = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return matrix;
    }
};

int main(){
    int n = 3;
    Solution su;
    auto ans = su.generateMatrix(n);
    for(auto nums : ans){
        for(auto num : nums){
            cout << " " << num;
        }
        cout << endl;
    }
}