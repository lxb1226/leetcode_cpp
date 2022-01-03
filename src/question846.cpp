#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
bool isNStraightHand(vector<int>& hand, int groupSize) {
       unordered_map<int,int> map;
       priority_queue<int, vector<int>, greater<int>> q;
       
       for(auto c : hand){
           map[c]++;
           q.push(c);
       }

       while(!q.empty()){
           int c = q.top();
           q.pop();
           if(map[c] == 0) continue;
           for(int i = 0; i < groupSize; i++){
               if(map[c + i] == 0) return false;
               map[c + i]--;
           }
       }

        return true;
    }

};

int main(){
    vector<int> hand{1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    Solution su;
    auto ans = su.isNStraightHand(hand, groupSize);

    cout << ans << endl;
}