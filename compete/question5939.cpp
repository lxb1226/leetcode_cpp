#include <iostream>
#include <vector>
 
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        long long sum = 0;
        if(n < 2 * k + 1){
            res.assign(n, -1);
            return res;
        }

        for(int i = 0; i < 2 * k + 1; i++){
            sum += nums[i];
        }

        for(int i = 0; i < n; ++i){
            if(i - k >= 0 && i + k < n){
                if(i == k){
                    res.push_back(sum / (2 * k + 1));
                }else{
                    sum -= nums[i - k - 1];
                    sum += nums[i + k];
                    res.push_back(sum / (2 * k + 1));
                }
            }else{
                res.push_back(-1);
            }
        }
        
        return res;
    }
};
 
int main(){
    // vector<int> nums{7,4,3,9,1,8,5,2,6};
    vector<int> nums{8};
    int k = 100000;
    Solution su;
    auto res = su.getAverages(nums, k);
    for(auto num : res){
        cout << num << " ";
    }
    cout << endl;
 
}