#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

void bfs(vector<vector<int>> &graph, int idx, vector<int> visited)
{
    int node;
    queue<int> queue_;
    queue_.push(idx);
    visited[idx] = 1;
    cout << idx << "-->";
    while (!queue_.empty())
    {
        node = queue_.front();
        queue_.pop();
        for (int i = 0; i < graph[node].size(); ++i)
        {
            if (graph[node][i] && !visited[i])
            {
                cout << i << "-->";
                visited[i] = 1;
                queue_.push(i);
            }
        }
    }

    cout << "NULL" << endl;
}

// dfs递归实现
void dfs_recursie(vector<vector<int>> &graph, int idx, vector<int>& visited){
    cout << idx << "-->";
    visited[idx] = 1;
    for(int i = 0; i < graph[idx].size(); i++){
        if(graph[idx][i] && !visited[i]){
            // visited[i] = 1;
            dfs_recursie(graph, i, visited);
            // visited[i] = 0;
        }
    }
}


void dfs(vector<vector<int>> &graph, int idx, vector<int> visited)
{
    int node;
    stack<int> stack_;
    stack_.push(idx);
    while (!stack_.empty())
    {
        node = stack_.top();
        stack_.pop();
        visited[node] = 1;
        cout << node << "-->";
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (graph[node][i] && !visited[i])
            {
                stack_.push(i);
            }
        }
    }

    cout << "NULL" << endl;
}

int prim(vector<vector<int>> &graph)
{   
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<int> visited(n, 0);

    distance[0] = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int u = -1, min = INT_MAX;
        for(int j = 0; j < n; ++j){
            if(visited[j] == 0 && distance[j] < min){
                u = j;
                min = distance[j];
            }
        }
        // 找不到小于INT_MAX的d[u]，则剩下的顶点和集合s不连通
        if(u == -1) return -1;
        visited[u] = 1;
        ans += distance[u];
        for(int v = 0; v < n; ++v){
            if(visited[v] == 0 && graph[u][v] != INT_MAX && graph[u][v] < distance[v]){
                distance[v] = graph[u][v];
            }
        }
    }
    
    return ans;
}

void floyd(vector<vector<int>>& graph, vector<vector<int>>& path){
    int n = graph.size();

    for(int k = 0; k < n; ++k){
        for(int v = 0; v < n; ++v){
            for(int w = 0; w < n; ++w){
                if(graph[v][w] - graph[v][k] > graph[k][w]){
                    graph[v][w] = graph[v][k] + graph[k][w];
                    path[v][w] = k;
                }
            }
        }
    }
}

void dijkstra(vector<vector<int>>& graph ,int u){
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    vector<int> visited(n, 0);

    distance[u] = 0;

    for(int i = 0; i < n; ++i){
        int min = INT_MAX, index = 0;
        for(int j = 0; j < n; ++j){
            if(visited[j] == 0 && distance[j] <= min){
                min = distance[j];
                index = j;
            }
        }

        visited[index] = 1;
        for(int j = 0; j < n; ++j){
            if(!visited[j] && graph[index][j] && distance[index] != INT_MAX && distance[index] + graph[index][j] < distance[j]){
                distance[j] = distance[index] + graph[index][j];
            }
        }
    }

    cout << "Vertex\t\tDistance from source vertex" << endl;
    for(int i = 0; i < n; ++i){
        char str = 65 + i;
        cout << str << "\t\t\t" << distance[i] << endl;
    }
    
}

void testPrim()
{
    cout << "test prim" << endl;
    vector<vector<int>> graph = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    prim(graph);
    cout << endl;
}

void testDijkstra(){
    vector<vector<int>> graph = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    cout << "test dijkstra" << endl;
    dijkstra(graph, 0);
}

void testBfs(){
    vector<vector<int>> graph = {{0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    vector<int> visited(graph.size(), 0);
    cout << "bfs :" << endl;
    bfs(graph, 0, visited);
}

void testDfs(){
    vector<vector<int>> graph = {{0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    vector<int> visited(graph.size(), 0);
    cout << "dfs_recursie :" << endl;
    dfs_recursie(graph, 0, visited);
    cout << endl;
}

int main()
{
    testBfs();
    testDfs();
    testPrim();
    testDijkstra();

    return 0;
}