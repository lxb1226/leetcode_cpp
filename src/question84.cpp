#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    // 法一：枚举宽
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int left = 0; left < n; ++left){
            int minHeight = INT_MAX;
            for(int right = left; right < n; ++right){
                minHeight = min(minHeight, heights[right]);
                ans = max(ans, (right - left + 1) * minHeight);
            }
        }

        return ans;
    }

    // 法二：枚举高
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int mid = 0; mid < n; ++mid){
            int height = heights[mid];
            int left = mid, right = mid;
            while(left - 1 >= 0 && heights[left - 1] >= height){
                --left;
            }
            while(right + 1< n && heights[right + 1] >= height){
                ++right;
            }
            ans = max(ans, (right - left + 1) * height);
        }

        return ans;
    }

    // 法三：单调栈
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> mono_stack;
        for(int i = 0; i < n; ++i){
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for(int i = n - 1; i >= 0; --i){
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n,n);
        stack<int> mono_stack;

        for(int i = 0; i < n; ++i){
            while(!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]){
                right[mono_stack.top()] = i;
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

int main(){

}