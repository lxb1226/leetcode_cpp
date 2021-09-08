#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // TODO:待看
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; ++i){
            for(int j = 0; j < (n + 1) / 2; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = tmp;
            }
        }
    }

    // void rotate_aux(vector<vector<int>>& matrix, int l, int r){
    //     if(l == r) return;
        
    //     // vector<int> tmp;
    //     // for(int i = l ; i <= r; i++){
    //     //     tmp.push_back(matrix[l][i]);
    //     // }

    //     vector<int> tmp{matrix[l].begin() + l, matrix[l].begin() + r + 1};
        
    //     for(int i = l, j = r; i <= r; ++i, --j){
    //         // 左复制到上
    //         matrix[l][j] = matrix[i][l];
    //         // 下复制到左
    //         matrix[i][l] = matrix[r][i];

    //         // 右复制到下
    //         matrix[r][i] = matrix[j][r];
    //         // 上复制到右
    //         matrix[j][r] = tmp[r - i];
    //     }
    //     cout << endl;
    //     rotate_aux(matrix, l + 1, r - 1);
    // }

};

int main(){
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);

    for(auto row : matrix){
        for(auto num : row){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}