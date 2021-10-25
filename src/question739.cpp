#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    // 法一：暴力法
    vector<int> dailyTemperatures1(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n), next(101, INT_MAX);

        for(int i = n - 1; i >= 0; i--){
            int warmerIndex = INT_MAX;
            for(int t = temperatures[i] + 1; t <= 100; ++t){
                warmerIndex = min(warmerIndex, next[t]);
            }

            if(warmerIndex != INT_MAX){
                ans[i] = warmerIndex - i;
            }
            next[temperatures[i]] = i;
        }

        return ans;
    }

    // 法二：单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;

        for(int i = 0; i < n; i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};

int main(){
    vector<int> temperatures{73,74,75,71,69,72,76,73};
    Solution su;
    auto ans = su.dailyTemperatures(temperatures);
    for(auto num : ans){
        cout << num << " ";
    }
    cout << endl;
}