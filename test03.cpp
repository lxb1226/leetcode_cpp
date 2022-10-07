#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> records;

    int tmp = 0;
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        records.push_back(tmp);
        sum += tmp;
    }
    long long total = 0;
    cin >> total;
    if(sum <= total){
        cout << -1 << endl;
        return 0;
    }
        
    sort(records.begin(), records.end());
    long long preSum = 0;
    int limit = -1;
    for(int i = 0; i < n; ++i){
        bool flag = false;
        if(preSum + (n - i) * records[i] > total){
            for(int j = records[i] - 1; j >= 0; j--){
                if(preSum + (n - i) * j <= total){
                    limit = j;
                    flag = true;
                    break;
                }
            }
        }else if(preSum + (n - i) * records[i] == total){
            limit = records[i];
            break;
        }
        if(flag) break;
        preSum += records[i];
    }

    cout << limit << endl;
    return 0;
}
