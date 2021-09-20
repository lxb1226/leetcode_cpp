#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 使用递归会超出时间限制，因此需要做优化。
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        int a = 1, b = 1;
        int tmp = 0;
        for(int i = 2; i <= n; i++){
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }

};

int main(){
    int n = 3;
    Solution s;
    auto ans = s.climbStairs(n);
    cout << ans << endl;
}