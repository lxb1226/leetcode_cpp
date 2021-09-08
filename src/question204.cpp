#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // int countPrimes(int n) {
    //     int ans = 0;
    //     for(int i = 2; i < n; ++i){
    //         ans += isPrime(i);
    //     }
    //     return ans;
    // }

    // bool isPrime(int n){
    //     for(int i = 2; i * i <= n; ++i){
    //         if(n % i == 0)
    //             return false;
    //     }
    //     return true;
    // }

    /**
     * 解法二：
     * 埃式筛
     * 
     */ 
    int countPrimes(int n){
        int count = 0;
        vector<bool> signs(n, true);
        for(int i = 2; i < n; i++){
            if(signs[i]){
                count++;
                for(int j = i + i; j < n; j += i){
                    signs[j] = false;
                }
            }
        }
        return count;
    }
};
int main(){
    int n = 10;
    Solution s;
    auto ans = s.countPrimes(n);
    cout << ans << endl;
}