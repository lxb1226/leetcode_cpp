#include<iostream>
#include<vector>

using namespace std;

int totalSum = 0;
int ans = INT_MAX;

void backtrace(int heros[10], vector<int>& visited, int num, int sum){
    if(num == 5){
        ans = min(ans, abs(totalSum - sum - sum));
        // cout << sum << " " << ans << endl;
        return;
    }

    for(int i = 0; i < 10; ++i){
        if(visited[i] == 0){
            visited[i] = 1;
            backtrace(heros, visited, num + 1, sum + heros[i]);
            visited[i] = 0;
        }
    }
}


int getValue(int heros[10]){
    for(int i = 0; i < 10; ++i){
        totalSum += heros[i];
    }
    vector<int> visited(10, 0);
    backtrace(heros, visited, 0, 0);
    return ans;
}

int main(){
    int heros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto value = getValue(heros);
    cout << value << endl;
    return 0;
}