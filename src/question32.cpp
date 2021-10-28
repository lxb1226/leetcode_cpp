#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int maxans = 0;
        stack<int> stk; // 栈底元素为最后一个没有被匹配的右括号的下标
        stk.push(-1);

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                // 如果栈为空，说明当前的右括号为没有被匹配的右括号
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                // 如果不为空，当前右括号的下标减去栈顶元素即为 以该右括号为结尾的最长有效括号的长度
                {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }

        return maxans;
    }

    int longestValidParentheses1(string s)
    {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if (left == right)
            {
                maxlength = max(maxlength, 2 * right);
            }
            else if (right > left)
            {
                left = right = 0;
            }
        }

        left = right = 0;
        for (int i = static_cast<int>(s.length() - 1); i >= 0; i--)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else
            {
                right++;
            }

            if (left == right)
            {
                maxlength = max(maxlength, 2 * right);
            }
            else if (left > right)
            {
                left = right = 0;
            }
        }

        return maxlength;
    }
};

int main()
{
    string s = "(()";
    Solution su;
    auto ans = su.longestValidParentheses(s);
    cout << ans << endl;
}