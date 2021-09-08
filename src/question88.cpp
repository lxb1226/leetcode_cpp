#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int len = m + n;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[--len] = nums1[i--];
            }else{
                nums1[--len] = nums2[j--];  
            } 
        }

        while(j >= 0) nums1[--len] = nums2[j--];
        
    }
};

int main(){
    // vector<int> nums1{1, 2, 3, 0, 0, 0};
    // vector<int> nums2{2, 5, 6};
    // int m = 3, n = 3;

    // vector<int> nums1{1};
    // vector<int> nums2;
    // int m = 1, n = 0;

    vector<int> nums1{0};
    vector<int> nums2{1};
    int m = 0, n = 1;
    Solution solution;
    solution.merge(nums1, m,nums2, n);
    
    auto print = [](const int& n){ std::cout << " " << n;};
    for_each(nums1.cbegin(), nums1.cend(), print);
    cout << endl;
    return 0;
}