#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    // 使用hash减少搜索时间
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        auto arrayHash = [fn = hash<int>{}](const array<int,26>& arr) -> size_t{
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num){
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for(string& str : strs){
            array<int, 26> counts{};
            int length = str.length();
            for(int i = 0; i < length; ++i){
                counts[str[i] - 'a']++;
            }
            
            mp[counts].emplace_back(str);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.emplace_back(it->second);
        }

        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 先排序
        unordered_map<string, vector<string>> mp;
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            ans.emplace_back(it->second);
        }

        return ans;
    }
};

int main(){

}