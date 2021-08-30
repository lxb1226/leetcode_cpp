#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return vector<int>{1};
        vector<int> pre{rowIndex+1};
        pre[0] = 1;
        vector<int> res(rowIndex+1);

        for(int i = 1; i <= rowIndex; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0)
                    res[j] = 1;
                else if(j == i)
                    res[j] = 1;
                else
                    res[j] = pre[j-1] + pre[j];
            }
            pre = res;
        }
        return res;
    }
};

int main(){
    int rowIndex = 0;
    Solution solution;
    auto res = solution.getRow(rowIndex);
    for(auto num : res){
        cout << " " << num;
    }
    cout << endl;
}
