#include <iostream>
#include <vector>
#include <unordered_map>
 
using namespace std;

bool isBalanced(unordered_map<char,int> &map){
    bool result = true;
    for(auto item : map){
        if((item.first >= 'a' && item.first <= 'z' && item.second != 0 && map[item.first + 32] == 0) || (item.first >= 'A' && item.second <= 'Z' && item.second != 0 && map[item.first - 32] == 0)){
            result = false;
        }
    }
    return result;
}

// 使用滑动窗口,思路是错的，
// 应该使用动态规划
int findMinLengthOfBalancedFrament(string str){
    unordered_map<char,int> map_;
    int i = 0, j = 0;
    while(i < str.size()){
        char c = str[i];
        if(!map_.count(c)){
            map_[c] = 0;
        }
        map_[c]++;
        i++;
        if((c >= 'A' && c <= 'Z' && !map_.count(c - 32)) || (c >= 'a' && c <= 'z' && !map_.count(c + 32))){
            continue;
        }

        // 不然就判断是否达到了balance fragments
        if(isBalanced(map_)){
            break;
        }
    }

    while(j < i){
        char c = str[j];
        map_[c]--;
        j++;
        if(!isBalanced(map_)){
            break;
        }
    }
    cout << "i : " << i << "j : " << j << endl;
    return i - j - 1;
}
 
int main(){
    string str = "CaBaabAc";
    int ans = findMinLengthOfBalancedFrament(str);
    cout << ans;
}