#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            // 逆推mid所在的i, j
            int i = mid / n;
            int j = mid % n;
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return false;
    }
};

int main(){
    // vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    // int target = 3;
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 13;
    Solution s;
    auto ans = s.searchMatrix(matrix, target);
    cout << ans << endl;

}