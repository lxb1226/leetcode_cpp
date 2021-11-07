#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;

    vector<int> tmp;

    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> rows(n, -1);
        backtrack(0, n, rows);
        return ans;
    }

    void backtrack(int row, int n, vector<int> &rows)
    {
        if (row == n)
        {
            ans.push_back(convertNum2Str(tmp));
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (check(row, col, rows))
            {
                rows[col] = row;
                tmp.push_back(col);
                backtrack(row + 1, n, rows);
                tmp.pop_back();
                rows[col] = -1;
            }
        }
    }

    bool check(int row, int col, vector<int> &rows)
    {
        if (rows[col] != -1)
        {
            return false;
        }
        bool result = true;
        for (int i = 0; i < rows.size(); ++i)
        {
            if (rows[i] != -1)
            {
                if (abs(row - rows[i]) == abs(col - i))
                {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }

    vector<string> convertNum2Str(vector<int> &nums)
    {
        int n = nums.size();
        string s(n, '.');
        vector<string> strs;
        for (int i = 0; i < n; ++i)
        {
            string tmp = s;
            tmp[nums[i]] = 'Q';
            strs.push_back(tmp);
        }

        return strs;
    }
};

int main()
{
    int n = 1;
    Solution su;
    auto ans = su.solveNQueens(n);
    for (auto strs : ans)
    {
        for (auto str : strs)
        {
            cout << str << " ";
        }
        cout << endl;
    }
}