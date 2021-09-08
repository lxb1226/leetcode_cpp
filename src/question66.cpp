#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i = digits.size() - 1; i >= 0; i--){
            digits[i] += 1;
            digits[i] %= 10;
            if(digits[i] != 0)
                return digits;
        }
        // vector<int> res(digits.begin(), digits.end());
        // res.insert(res.begin(), 1);
        digits.insert(digits.begin(), 1);
        return digits; 
    }
};

int main(){
    vector<int> digits = {9};
    Solution solution;
    auto res = solution.plusOne(digits);
    for(auto num : res){
        cout << num << endl;
    }
    return 0;

}

