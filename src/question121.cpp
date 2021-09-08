#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 10001;
        int total = 0;
        for(auto price : prices){
            if(price < minPrice){
                minPrice = price;
            }
            if(total < price - minPrice){
                total = price - minPrice;
            }
        }
        return total;
    }
};

int main(){
    vector<int> prices{7, 1, 5, 3, 6, 4};
    Solution solution;
    int res = solution.maxProfit(prices);
    cout << res << endl;
}