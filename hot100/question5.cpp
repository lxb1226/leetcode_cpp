#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    // 法一
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        int maxLen = 1, begin = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = 0;
        }
        for (int L = 2; L <= n; ++L)
        {
            for (int i = 0; i < n; ++i)
            {
                int j = L + i - 1;
                if (j >= n)
                    break;

                if (s[i] != s[j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (j - i < 3)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] == 1 && j - i + 1 > maxLen)
                {
                    maxLen = L;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};

int main()
{
}