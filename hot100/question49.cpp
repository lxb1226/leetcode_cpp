#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto &str : strs){
            string tmp = str;
            sort(str.begin(), str.end());
            mp[str].emplace_back(tmp);
        }
        vector<vector<string>> res;
        for(auto &item : mp){
            res.emplace_back(item.second);
        }

        return res;
    }
};

int main()
{
}