#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while(s){
            ret += s & 1;
            s >>= 1;
        }

        return ret;
    }
};

int main(){
    int x = 1, y = 4;
    Solution su;
    auto ans = su.hammingDistance(x, y);
    cout << ans << endl;
}