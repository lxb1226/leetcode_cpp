#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int max = 0, index = 0;
        for(auto n : nums){
            m[n]++;
            if(m[n] > max){
                max = m[n];
                index = n;
            }
        }
        return index;
    }
};
int main(){
    vector<int> nums{3, 2, 3};
    Solution s;
    auto res = s.majorityElement(nums);
    cout << res << endl; 
}