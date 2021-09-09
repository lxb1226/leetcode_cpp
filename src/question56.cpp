#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

class Solution {
public:
    // TODO:大概想法没错，但是怎么合并呢还需要进一步思考
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 按第二个元素升序排序
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        bool flag = false;
        vector<int> pre = intervals[0];
        int i = 1;
        while(i < intervals.size()){
            vector<int> tmp = intervals[i];


            if(flag && i != intervals.size() - 1){
                pre = intervals[i];
                flag = false;
            }else if(flag && i == intervals.size() - 1){
                ans.push_back(pre);
                flag = false;
            }else{
                if(tmp[0] <= pre[1]){
                    // 合并
                    pre = vector<int>{pre[0], max(pre[1], tmp[1])};
                }else{
                    // 加入到集合，并
                    ans.push_back(pre);
                    flag = true;
                }
            }
            i++;
        }

        return ans;
    }
};

int main(){

    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
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