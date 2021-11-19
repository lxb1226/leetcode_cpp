#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 位运算 还可以进一步优化
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);
        int max_val = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < words[i].length(); ++j){
                masks[i] |= 1 << (words[i][j] - 'a');
            }
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; ++j){
                if((masks[i] & masks[j]) == 0){
                    max_val = max(max_val, static_cast<int>(words[i].length() * words[j].length()));
                }
            }
        }

        return max_val;
    }


    // 法一：暴力法 未超时 O(n^2 * max(word))
    int maxProduct2(vector<string>& words) {
        int n = words.size();
        int max_val = 0;
        for(int i = 0; i < n - 1; ++i){
            vector<int> chars(26);
            for(auto &c : words[i]){
                chars[c - 'a'] = 1;
            }
            for(int j = i + 1; j < n; ++j){
                if(compareString(chars, words[j])){
                    max_val = max(max_val, static_cast<int>(words[i].length() * words[j].length()));
                }
            }
        }
        return max_val;
    }

    // 位运算，进一步优化
    int maxProduct3(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);
        unordered_map<int,int> map;
        int max_val = 0;
        for(int i = 0; i < n; ++i){
            int mask = 0;
            for(int j = 0; j < words[i].length(); ++j){
                mask |= 1 << (words[i][j] - 'a');
            }
            if(map.count(mask)){
                if(words[i].length() > map[mask]){
                    map[mask] = words[i].length();
                }
            }else{
                    map[mask] = words[i].length(); 
            }
        }

        for(auto [mask1, _] : map){
            int wordLength1 = map[mask1];
            for(auto [mask2, _] : map){
                if((mask1 & mask2) == 0){
                    int wordLength2 = map[mask2];
                    max_val = max(max_val, wordLength1 * wordLength2);
                }
            }
        }

        return max_val;
    }


    // 法一：暴力法 未超时 O(n^2 * max(word))
    int maxProduct4(vector<string>& words) {
        int n = words.size();
        int max_val = 0;
        for(int i = 0; i < n - 1; ++i){
            vector<int> chars(26);
            for(auto &c : words[i]){
                chars[c - 'a'] = 1;
            }
            for(int j = i + 1; j < n; ++j){
                if(compareString(chars, words[j])){
                    max_val = max(max_val, static_cast<int>(words[i].length() * words[j].length()));
                }
            }
        }
        return max_val;
    }
 

    bool compareString(vector<int>& chars, string word){
        bool res = true;
        for(auto &c : word){
            if(chars[c - 'a'] == 1){
                res = false;
                break;
            }
        }
        return res;
    }
};

int main(){
    // vector<string> words{"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> words{"a","ab","abc","d","cd","bcd","abcd"};
    Solution su;
    auto ans = su.maxProduct(words);
    cout << ans << endl;
}