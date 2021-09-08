#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 法一：暴力法 超出时间限制
    int maxArea1(vector<int>& height) {
        int area = 0, tmp = 0;
        for(int i = 0; i < height.size() - 1; i++){
            for(int j = i + 1; j <= height.size() - 1; j++){
                    tmp = (j - i) * min(height[i], height[j]);
                    if(area < tmp){
                        area = tmp;
                    }
            }
        }
        return area;
    }

    // 方法二：双指针法
    // TODO:还需要做第二遍
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while(l < r){
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if(height[l] <= height[r]){
                ++l;
            }else{
                --r;
            }
        }

        return ans;
    }

};

int main(){
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution s;
    auto ans = s.maxArea(height);
    cout << ans << endl;
}