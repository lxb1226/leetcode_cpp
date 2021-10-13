#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
    }

    void helper(vector<vector<int>> &ans, vector<int> &tmp, vector<int> nums, int n, int k)
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
    }
};

int main()
{
}