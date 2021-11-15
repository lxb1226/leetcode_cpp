#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 法一：暴力法求解 时间复杂度O(n^2) 超时，正常
    // 考虑有数学规律
    int bulbSwitch(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> bulks(n, 1);
        
        for(int i = 2; i <= n; i++){
            if(i == 2){
                for(int j = i - 1; j < n; j += 2){
                    bulks[j] = 0;
                }
            }else{
                for(int j = i - 1; j < n; j += i){
                    bulks[j] = !bulks[j];
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bulks[i] == 1){
                cnt++;
            }
        }
        return cnt;
    }

    int bulbSwitch(int n) {
        if(n <= 1){
            return n;
        }else if(n == 2){
            return 1;
        }

        // 考虑对于每个位置，会转变多少次,也就是说分解因式，计算出它的因式。这里因式需要除去1
        unordered_map<int,int> map_;
        int cnt = 0;
        for(int i = 3; i <= n; i++){
            cnt += getFactor(i);
        }

        return cnt;
    }

    int getFactor(int num){
        int cnt = 0;
        for(int i = 2; i <= num / 2; i++){
            if(num % i != 0){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

}