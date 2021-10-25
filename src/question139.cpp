#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // TODO:动态规划 看不懂
    bool wordBreak(string s, vector<string> &wordDict)
    {
        auto wordDictSet = unordered_set<string>();

        for (auto word : wordDict)
        {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    Solution su;
    auto ans = su.wordBreak(s, wordDict);
    cout << ans << endl;
}