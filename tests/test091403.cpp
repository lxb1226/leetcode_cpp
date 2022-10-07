#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 999999;
const int N = 520;

int main(){
    int n, startId, endId, ttl;
    cin >> n >> startId >> endId >> ttl;
    
    vector<vector<int> > edges(N, vector<int>(N, INF));
    vector<int> ttls(N);
    vector<int> disp(N, INF);
    vector<int> visited(N, 1);
    int a, b, c;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        edges[a][b] = edges[b][a] = c;
        visited[a] = 0;
        visited[b] = 0;
    }

    for(int i = 0; i < N; ++i){
        edges[i][i] = 0;
    }

    disp[startId] = 0;
    ttls[startId] = 0;
    // visited[startId] = 1;
    for(int i = 0; i < N; ++i){
        int u = -1, min = INF;
        for(int j = 0; j < N; j++){
            if(visited[j] == 0 && ttls[j] < ttl && disp[j] <= min){
                u = j;
                min = disp[j];
            }
        }

        if(u == -1){
            break;
        }
        
        cout << "u : " << u << endl;
        visited[u] = 1;
        for(int v = 0; v < N; v++){
            if(visited[v] == 0 && ttls[v] < ttl && edges[u][v] != INF){
                if(disp[u] + edges[u][v] < disp[v]){
                    disp[v] = disp[u] + edges[u][v];
                    ttls[v] = ttls[u] - 1;
                    // cout << "disp[u] : " << disp[u] <<  "u : " << u << " v : " <<  v << " " << endl;
                }
            }
        }
    }


    cout << disp[endId] << endl;
    return 0;

}