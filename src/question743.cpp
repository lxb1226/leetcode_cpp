#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        const int inf = INT_MAX / 2;
        vector<vector<int>> edges(n, vector<int>(n, inf));
        for (auto &time : times)
        {
            edges[time[0] - 1][time[1] - 1] = time[2];
        }

        vector<int> distance(n, inf);
        vector<int> visited(n, 0);

        distance[k - 1] = 0;

        for (int i = 0; i < n; ++i)
        {
            int index = -1;
            for (int j = 0; j < n; ++j)
            {
                if (visited[j] == 0 && (index == -1 || distance[j] < distance[index]))
                {
                    index = j;
                }
            }

            visited[index] = 1;
            for (int j = 0; j < n; ++j)
            {
                distance[j] = min(distance[j], distance[index] + edges[index][j]);
            }
        }

        int ans = *max_element(distance.begin(), distance.end());
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4, k = 2;
    Solution su;
    auto res = su.networkDelayTime(times, n, k);

    cout << res << endl;
    return 0;
}