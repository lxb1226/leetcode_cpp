#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] < b[0]; });

        for (auto &interval : intervals)
        {
            int L = interval[0], R = interval[1];
            if (!ans.empty() && ans.back()[1] >= L)
            {
                ans.back()[1] = max(R, ans.back()[1]);
            }
            else
            {
                ans.push_back(interval);
            }
        }

        return ans;
    }
};

int main()
{
}