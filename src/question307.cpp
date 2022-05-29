/*
 * @Author: heyjude
 * @Date: 2022-04-04 20:38:17
 * @LastEditors: heyjude
 * @LastEditTime: 2022-04-04 20:38:18
 * @FilePath: /leetcode_cpp/src/question307.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by heyjude, All Rights Reserved. 
 */
#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class NumArray {
public:
    vector<int> data;
    vector<int> prefix;
    NumArray(vector<int>& nums):data(nums){
        int n = nums.size();
        prefix[0] = nums[0];
        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i - 1] + nums[i];
        }
    }
    
    void update(int index, int val) {
        // 更新前缀和
        for(int i = index; i < prefix.size(); ++i){
            prefix[i] += (val - data[i]);
        }
        data[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - prefix[left - 1];
    }
};


int main()
{
    
}