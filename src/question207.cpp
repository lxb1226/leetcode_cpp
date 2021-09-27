#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    // TODO:
    void dfs(int u)
    {
        visited[u] = 1;
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }

        visited[u] = 2;
    }

    // 判断一个有向图是否有回路 可以用dfs或者拓扑排序
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto &info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        return valid;
    }
};

int main()
{
}