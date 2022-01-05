#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    vector<int> arr{1, 2, 3, 4, 5};

    auto iter = max_element(arr.begin(), arr.end());
    cout << *iter << endl;

    return 0;
}