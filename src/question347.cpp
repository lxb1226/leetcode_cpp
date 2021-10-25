#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int>& m, pair<int, int>& n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> occurrences;
        for(auto& v : nums){
            occurrences[v]++;
        }

        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);
        for(auto& it : occurrences){
            if(q.size() == k){
                if(q.top().second < it.second){
                    q.pop();
                    q.emplace(it);
                }
            }else{
                q.emplace(it);
            }
        }

        vector<int> ret;
        while(!q.empty()){
            ret.emplace_back(q.top().first);
            q.pop();
        }

        return ret;
    }
};

int main(){
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution su;
    auto ans = su.topKFrequent(nums, k);
    for(auto& num : ans){
        cout << num << " ";
    }
    cout << endl;
}