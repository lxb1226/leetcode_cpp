#include <iostream>
#include <vector>

using namespace std;

void backtrace(vector<int>& nums, int numSize, int& returnSize, vector<vector<int> >& ans, vector<int>& path, vector<int>& visited){
    if(path.size() == nums.size()){
        ans.push_back(path);
        returnSize++;
        return;
    }

    for(int i = 0; i < numSize; ++i){
        if(visited[i] == 0){
            visited[i] = 1;
            path.push_back(nums[i]);
            backtrace(nums, numSize, returnSize, ans, path, visited);
            path.pop_back();
            visited[i] = 0;
        }
    }
}


vector<vector<int>> premute(vector<int>& nums, int numSize, int& returnSize){
    vector<vector<int> > ans;
    vector<int> path;
    vector<int> visited(numSize, 0);
    backtrace(nums, numSize, returnSize, ans, path, visited);

    return ans;
}

int main(){
    vector<int> nums {1, 2, 3};
    int numSize = 3;
    int returnSize = 0;

    auto ans = premute(nums, numSize, returnSize);
    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < numSize; ++j){
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}