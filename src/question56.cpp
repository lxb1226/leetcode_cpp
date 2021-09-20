#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按第二个元素升序排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
                // if(a[1] < b[1]){
                //     return true;
                // }else if(a[1] == b[1]){
                //     return a[0] <= b[0];
                // }else{
                //     return false;
                // }
                return a[0] < b[0];
            });
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while(i < n - 1){
            if(intervals[i][1] >= intervals[i + 1][0]){
                // 合并区间
                int minValue = min(intervals[i][0], intervals[i+1][0]);
                int maxValue = max(intervals[i][1], intervals[i+1][1]);
                intervals[i+1] = {minValue, maxValue};
            }else{
                // 不合并区间，并添加到ans中
                ans.push_back(intervals[i]);
            }
            i++;
        }
        ans.push_back(intervals[n - 1]);
        return ans;
    }
};

int main(){

    // vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    // vector<vector<int>> intervals{{1, 4}, {0, 4}};
    vector<vector<int>> intervals{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution s;
    auto ans = s.merge(intervals);
    for(auto interval : ans){
        for(auto num : interval){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}