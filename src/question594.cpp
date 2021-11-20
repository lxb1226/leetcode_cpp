#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       int begin = 0;
       int res = 0;
       for(int end = 0; end < nums.size(); end++){
           while(nums[end] - nums[begin] > 1){
               begin++;
           }
           if(nums[end] - nums[begin] == 1){
               res = max(res, end - begin + 1);
           }
       } 

       return res;
    }

    // 法二
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> cnt;
        int res = 0;
        for(int num : nums){
            cnt[num]++;
        }

        for(auto [key, val] : cnt){
            if(cnt.count(key + 1)){
                res = max(res, val + cnt[key + 1]);
            }
        }

        return res;
    }

};
 
int main(){
 
 
}