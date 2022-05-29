#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int k;
    string b;
    cin >> k;
    cin >> b;

    string a(b.size(), '0');

    for (int i = k; i < b.size() - k; ++i)
    {
        if (b[i] == '1')
        {
            // A[i - k] = 1 || A[i + k] = 1
            a[i + k] = '1';
        }
        else
        {
            // A[i - k] == 0 && A[i + k] == 0
            a[i - k] = '0';
            a[i + k] = '0';
        }
    }

    cout << a << endl;
    return 0;
}