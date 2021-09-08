#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

constexpr int charToNum(char c){return c - '0';};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // col
        for(int i = 0; i < 9; i++){
            unordered_map<int,bool> m;
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = charToNum(board[i][j]);
                    if(m.find(num) != m.end()){
                        return false;
                    }
                    m[num] = true;
                }
            }
        }

        // row
        for(int i = 0; i < 9; i++){
            unordered_map<int,bool> m;
            for(int j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    int num = charToNum(board[j][i]);
                    if(m.find(num) != m.end()){
                        return false;
                    }
                    m[num] = true;
                }
            }
        }

        // 3*3
        for(int i = 0; i < 3 ; i += 3){
            for(int k = 0; k < 3; ++k){
                unordered_map<int,bool> m;
                for(int j = 3 * k; j < 3 + 3*k; ++j){
                    if(board[i][j] != '.'){
                        int num = charToNum(board[i][j]);
                        if(m.find(num) != m.end()){
                            return false;
                        }
                        m[num] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main(){

}