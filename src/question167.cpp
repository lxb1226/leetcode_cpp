#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                break;
                
            }else if(numbers[i] + numbers[j] > target){
                j--;
            }else{
                i++;
            }
        }
        return {i + 1, j + 1};
    }
};

int main(){
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    Solution s;
    auto res = s.twoSum(nums, target);
    for(auto num : res){
        cout << " " << num;
    }
    cout << endl;
}