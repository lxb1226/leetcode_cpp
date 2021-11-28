#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        int max_idx = distance(nums.begin(), max_element(nums.begin(), nums.end()));
        int min_idx = distance(nums.begin(), min_element(nums.begin(), nums.end()));
        
        int max_val = max(max_idx, min_idx);
        int min_val = min(max_idx, min_idx);
        
        // 判断几种不同的情况
        // 1.一个从前面删，一个从后面删
        cout << max_val << " " << min_val << endl;
        int res1 = min_val + 1 + n - max_val;
        // 2.都从前面删
        int res2 = max_val + 1;
        // 3.都从后面删
        int res3 = n - min_val + 1;
        cout << res1 << " " << res2 << " " << res3 << endl;
        return min({res1, res2, res3});
        
    }
};
 
int main(){
    vector<int> nums{2,10,7,5,4,1,8,6};
    Solution su;
    auto ans = su.minimumDeletions(nums);
    cout << ans << endl;
}