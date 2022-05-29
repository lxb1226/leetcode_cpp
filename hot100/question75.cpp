#include <bits/stdc++.h>
#include "../templates/data_struct.h"

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int idx0 = 0, idx1 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[idx0]);
                if (idx0 < idx1)
                {
                    swap(nums[i], nums[idx1]);
                }

                idx0++;
                idx1++;
            }
            else if (nums[i] == 1)
            {
                swap(nums[i], nums[idx1]);
                idx1++;
            }
        }
    }
};
int main()
{
}