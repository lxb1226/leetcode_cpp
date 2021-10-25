#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }

        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--)
        {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--)
            {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }

        for (int i = m + n - 1; i > 0; i--)
        {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }

        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n)
        {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c : ans)
        {
            c += '0';
        }
        return ans;
    }

    string multiply1(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            string curr;
            int add = 0;
            for (int j = n - 1; j > i; j--)
            {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--)
            {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while (add != 0)
            {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for (auto &c : curr)
            {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }

    string addStrings(string &num1, string &num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0)
        {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto &c : ans)
        {
            c += '0';
        }
        return ans;
    }
};

int main()
{
    string num1 = "999", num2 = "999";
    Solution su;
    auto ans = su.multiply(num1, num2);
    cout << ans << endl;
}