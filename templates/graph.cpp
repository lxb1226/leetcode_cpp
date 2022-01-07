#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// 并查集
// vector<int> fa;

// // 寻找根节点 无路径压缩
// int find(int u){
//     if(fa[u] == u) return u;
//     else return find(fa[u]);
// }

// // 寻找根节点 路径压缩
// int find(int u){
//     if(fa[u] == u) return u;
//     else{
//         fa[u] = find(fa[u]);
//         return fa[u];
//     }
// }

// // 合并两个集合数
// void merge(int u, int v){
//     int fau = find(u);
//     int fav = find(v);
//     if(fau != fav) fa[fau] = fav;
//     return;
// }

// bfs算法
void bfs(vector<vector<int>> &graph, int idx, vector<int>& visited)
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
}

// dfs算法
void dfs(vector<vector<int>> &graph, int idx, vector<int>& visited){
    cout << idx << "-->";   // 访问节点idx
    visited[idx] = 1;   // 设置已访问节点
    for(int i = 0; i < graph[idx].size(); i++){ // 遍历idx节点的邻接节点，并访问其没有被访问的节点
        if(graph[idx][i] && !visited[i]){           
            dfs(graph, i, visited);
        }
    }
}

// prim算法
void prim(vector<vector<int>> &graph)
{   
    int min, i, j, k;
    int n = graph.size();
    vector<int> adjvex(n, 0);   // 保存相关顶点下标
    vector<int> lowcost(n, 0);  // 保存相关顶点间边的权值

    lowcost[0] = 0; // 初始化第一个权值为0，即v0加入生成树
    adjvex[0] = 0;  // 初始化第一个顶点下标为0

    for(int i = 1; i < n; ++i){
        lowcost[i] = graph[0][i];   // 将v0顶点与之组成边的权值存入数组
        adjvex[i] = 0;  // 初始化都为v0的下标
    }

    for(int i = 1; i < n; ++i){
        min = INT_MAX;  // 初始化最小权值
        j = 1; k = 0;
        while(j < n){   // 循环全部顶点，找到最小权值
            if(lowcost[j] != 0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        cout << "(" << adjvex[k] << " , " << k << ") ";
        // 更新
        for(j = 1; j < n; ++j){
            // 若下标为k 顶点各边权值小于此前这些顶点未被加入生成树权值
            if(lowcost[j] != 0 && graph[k][j] < lowcost[j]){
                lowcost[j] = graph[k][j];   // 将较小权值存入lowcost
                adjvex[j] = k;  // 将下标为k的顶点存入adjvex
            }
        }
    }
}

// floyd算法
void floyd(vector<vector<int>>& graph, vector<vector<int>>& path){
    int n = graph.size();

    // k为中间点
    for(int k = 0; k < n; ++k){
        for(int v = 0; v < n; ++v){ // v为起点
            for(int w = 0; w < n; ++w){ // w为终点
                if(graph[v][w] - graph[v][k] > graph[k][w]){
                    graph[v][w] = graph[v][k] + graph[k][w];    // 更新最小路径
                    path[v][w] = k; // 更新最小路径中间顶点
                }
            }
        }
    }
}

// dijkstra算法
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

// 拓扑排序算法
bool TopologicalSort(const vector<vector<int>>& graph){
    stack<int> stk;
    int n = graph.size();
    vector<int> indegree(n, 0);
    // 统计入度
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(graph[i][j] != INT_MAX){
                indegree[j]++;
            }
        }
    }

    // 将所有入度为0的顶点进栈
    for(int i = 0; i < n; ++i){
        if(indegree[i] == 0)
            stk.push(i);
    }

    int cnt = 0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        cout << node << " ";
        cnt++;
        for(int i = 0; i < n; ++i){
            if(graph[i][node] != INT_MAX && indegree[i] != 0){
                if(--indegree[i] == 0){
                    stk.push(i);
                }
            }
        }
    }

    return cnt == n;
}

// krusal算法
struct edge{
    int u, v;
    int weight;
};

bool compare(edge a, edge b){
    return a.weight < b.weight;
}

int findFather(int a, vector<int>& father){
    while(a != father[a]){
        a = father[a];
    }
    return a;
}

void kruskal(int n, vector<edge> Edge){
    vector<int> father(n, 0); // 记录每个节点的父亲
    vector<int> result(n, 0); // 存储最后获得的各条边
    sort(Edge.begin(), Edge.end(), compare);
    for(int i = 0; i < n; ++i){
        father[i] = i;
    }

    for(int i = 0; i < Edge.size() && result.size() < n - 1; ++i){
        int u = Edge[i].u;
        int v = Edge[i].v;

        if(findFather(u, father) != findFather(v, father)){ // 判断父节点是否相同
            result.push_back(Edge[i].weight);
            father[findFather(u, father)] = father[findFather(v, father)];  // 将两点并入一个集合
        }
    }

    if(result.size() != n - 1){
        cout << "result.size() : " << result.size() << ",该图不连通" << endl;
        return;
    }else{
        cout << "最小生成树的各边如下: " << endl;
        for(int i = 0; i < result.size(); ++i){
            cout << result[i] << endl;
        }
    }
}

void testKruskal(){
    cout << "test kruskal" << endl;
    vector<vector<int>> graph = {
        {0, 10, INT_MAX, INT_MAX, INT_MAX,11, INT_MAX, INT_MAX, INT_MAX},
        {10, 0, 18, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 12},
        {INT_MAX, INT_MAX, 0, 22, INT_MAX, INT_MAX, INT_MAX, INT_MAX,8},
        {INT_MAX, INT_MAX, 22, 0, 20, INT_MAX, INT_MAX, 16, 21},
        {INT_MAX, INT_MAX, INT_MAX, 20, 0, 26, INT_MAX, 7, INT_MAX},
        {11, INT_MAX, INT_MAX, INT_MAX, 26, 0, 17, INT_MAX, INT_MAX},
        {INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 17, 0, 19, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 16, 7, INT_MAX, 19, 0, INT_MAX},
        {INT_MAX, 12, 8, 21, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    vector<edge> Edges;

    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph.size(); ++j){
            if(graph[i][j] != INT_MAX){
                Edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    kruskal(graph.size(), Edges);
    cout << endl;
}

void testTopologicalSort(){
    vector<vector<int>> graph = {
        {0, 10, INT_MAX, INT_MAX, INT_MAX,11, INT_MAX, INT_MAX, INT_MAX},
        {10, 0, 18, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 12},
        {INT_MAX, INT_MAX, 0, 22, INT_MAX, INT_MAX, INT_MAX, INT_MAX,8},
        {INT_MAX, INT_MAX, 22, 0, 20, INT_MAX, INT_MAX, 16, 21},
        {INT_MAX, INT_MAX, INT_MAX, 20, 0, 26, INT_MAX, 7, INT_MAX},
        {11, INT_MAX, INT_MAX, INT_MAX, 26, 0, 17, INT_MAX, INT_MAX},
        {INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 17, 0, 19, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 16, 7, INT_MAX, 19, 0, INT_MAX},
        {INT_MAX, 12, 8, 21, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};

    cout << "test TopologicalSort" << endl;
    auto res = TopologicalSort(graph);
    cout << "the res of TopologicalSort is " << res << endl;
}

void testFloyd(){
    vector<vector<int>> graph = {
        {0, 10, INT_MAX, INT_MAX, INT_MAX,11, INT_MAX, INT_MAX, INT_MAX},
        {10, 0, 18, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 12},
        {INT_MAX, INT_MAX, 0, 22, INT_MAX, INT_MAX, INT_MAX, INT_MAX,8},
        {INT_MAX, INT_MAX, 22, 0, 20, INT_MAX, INT_MAX, 16, 21},
        {INT_MAX, INT_MAX, INT_MAX, 20, 0, 26, INT_MAX, 7, INT_MAX},
        {11, INT_MAX, INT_MAX, INT_MAX, 26, 0, 17, INT_MAX, INT_MAX},
        {INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 17, 0, 19, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 16, 7, INT_MAX, 19, 0, INT_MAX},
        {INT_MAX, 12, 8, 21, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
    vector<vector<int>> path(graph.size(), vector<int>(graph.size(), 0));
    cout << "test floyd" << endl;
    floyd(graph, path);
    cout << "after floyd, the value of graph : " << endl;
    for(int i = 0; i < graph.size(); ++i){
        for(int j = 0; j < graph.size(); ++j){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << "after floyd, the value of path : " << endl;
    for(int i = 0; i < path.size(); ++i){
        for(int j = 0; j < path.size(); ++j){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
    
}

void testPrim()
{
    cout << "test prim" << endl;
    vector<vector<int>> graph = {
        {0, 10, INT_MAX, INT_MAX, INT_MAX,11, INT_MAX, INT_MAX, INT_MAX},
        {10, 0, 18, INT_MAX, INT_MAX, INT_MAX, 16, INT_MAX, 12},
        {INT_MAX, INT_MAX, 0, 22, INT_MAX, INT_MAX, INT_MAX, INT_MAX,8},
        {INT_MAX, INT_MAX, 22, 0, 20, INT_MAX, INT_MAX, 16, 21},
        {INT_MAX, INT_MAX, INT_MAX, 20, 0, 26, INT_MAX, 7, INT_MAX},
        {11, INT_MAX, INT_MAX, INT_MAX, 26, 0, 17, INT_MAX, INT_MAX},
        {INT_MAX, 16, INT_MAX, INT_MAX, INT_MAX, 17, 0, 19, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 16, 7, INT_MAX, 19, 0, INT_MAX},
        {INT_MAX, 12, 8, 21, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};
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

void bfsTraverse(){
    vector<vector<int>> graph = {{0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    vector<int> visited(graph.size(), 0);
    cout << "bfs traverse :" << endl;
    for(int i = 0; i < graph.size(); ++i){
        if(!visited[i]){
            bfs(graph, i, visited);
        }
    }
    cout << endl;
}

void dfsTraverse(){
    vector<vector<int>> graph = {{0, 1, 0, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    vector<int> visited(graph.size(), 0);
    cout << "dfs traverse :" << endl;
    for(int i = 0; i < graph.size(); ++i){
        if(!visited[i]){
            dfs(graph, i, visited);
        }
    }
    cout << endl;
}

int main()
{
    bfsTraverse();
    dfsTraverse();
    testPrim();
    testDijkstra();
    testFloyd();
    testTopologicalSort();
    testKruskal();

    return 0;
}