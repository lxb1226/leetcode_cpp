#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> visited, path;
    void dfs(vector<int>& graph, int u, int& num){
        visited[u] = 1;
        if(visited[graph[u]] != 1){
            path[u] = graph[u];
            num++;
            dfs(graph, graph[u], num);
        }
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int num, pre,v, max_num = 0;
        for(int i = 0; i < n; ++i){
            visited.assign(n, 0);
            path.assign(n, -1);
            num = 1;
            dfs(favorite, i, num);
            v = i;
            while(path[v] != -1){
                pre = v;
                v = path[v];
            }
            if(favorite[v] == i || favorite[v] == pre){
                max_num = max(num, max_num);
            }
        }
        
        return max_num;
    }
};

int main(){

    // vector<int> favorite{2, 2, 1, 2};
    vector<int> favorite{1, 2, 0};
    Solution su;
    auto res = su.maximumInvitations(favorite);
    cout << res << endl;
    return 0;
}