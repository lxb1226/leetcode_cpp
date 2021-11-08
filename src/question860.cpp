#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        unordered_map<int, int> map{make_pair(5, 0), make_pair(10, 0)};
        bool result = true;
        for (auto bill : bills)
        {
            if (bill == 5)
            {
                map[bill]++;
            }
            else if (bill == 10)
            {
                if (map[5] < 1)
                {
                    result = false;
                    break;
                }
                map[5] -= 1;
                map[bill]++;
            }
            else
            {
                if (map[10] >= 1 && map[5] >= 1)
                {
                    map[10]--;
                    map[5]--;
                }
                else if (map[5] >= 3)
                {
                    map[5] -= 3;
                }
                else
                {
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    Solution su;
    auto ans = su.lemonadeChange(bills);
    cout << ans << endl;
}