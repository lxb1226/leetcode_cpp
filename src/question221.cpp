#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                if(matrix[i][j] == '1'){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return 0;
        }

        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(matrix[i][j] == '1'){
                    maxSide = max(maxSide, 1);
                    int currentMaxSide = min(rows - i, columns - j);
                    for(int k = 1; k < currentMaxSide; k++){
                        bool flag = true;
                        if(matrix[i + k][j + k] == '0'){
                            break;
                        }

                        for(int m = 0; m < k; m++){
                            if(matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0'){
                                flag = false;
                                break;
                            }
                        }
                        
                        if(flag){
                            maxSide = max(maxSide, k + 1);

                        }else{
                            break;
                        }
                    }
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};

int main(){

}