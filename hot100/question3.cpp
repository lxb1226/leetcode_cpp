#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> ooc;
        int rk = -1, ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
            {
                ooc.erase(s[i - 1]);
            }
            while (rk + 1 < n && !ooc.count(s[rk + 1]))
            {
                ooc.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }

        return ans;
    }
};

int main()
{
}