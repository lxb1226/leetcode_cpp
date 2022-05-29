#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int idx, int height, int& max_height){
        visited[idx] = 1;
        for(int i = 0; i < graph[idx].size(); ++i){
            if(visited[graph[idx][i]] == 0){
                
                visited[i] = 1;
                dfs(graph, visited, i, height + 1,max_height);
                visited[i] = 0;
                
            }else{
                max_height = max(max_height, height);
            }

        }
        visited[idx] = 0;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> ans;
        int min_height = INT_MAX;
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        for(int i = 0; i < n; i++){
            int height = 0;
            
            dfs(graph,visited, i, 0, height);
            if(height < min_height){
                min_height = height;
                ans.clear();
                ans.push_back(i);
            }else if(height == min_height){
                ans.push_back(i);
            }
        }

        return ans;
    }

    // 拓扑排序
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     if(n == 1) return {0};
    //     vector<int> res;
    //     vector<int> degree(n);
    //     vector<vector<int>> map(n);
    //     for(int i = 0; i < edges.size(); ++i){
    //         int v1 = edges[i][0];
    //         int v2 = edges[i][1];
    //         degree[v1]++;
    //         degree[v2]++;
    //         map[v1].push_back(v2);
    //         map[v2].push_back(v1);
    //     }

    //     queue<int> q;
    //     for(int i = 0; i < n; i++){
    //         if(degree[i] == 1)
    //             q.push(i);
    //     }

    //     while(!q.empty()){
    //         res.clear();
    //         int size = q.size();
    //         while(size--){
    //             int cur = q.front();
    //             q.pop();
    //             res.push_back(cur);
    //             degree[cur]--;
    //             for(auto i : map[cur]){
    //                 degree[i]--;
    //                 if(degree[i] == 1)
    //                     q.push(i);
    //             }
    //         }
    //     }

    //     return res;
    // }
};

int main(){
    vector<vector<int>> edges{{1, 0}, {1, 2}, {1, 3}};
    int n = 4;
    Solution su;
    auto res = su.findMinHeightTrees(n, edges);
    for(auto & num : res){
        cout << num << " ";
    }
    cout << endl;
}