#include <bits/stdc++.h>
typedef long long lli;
using namespace std;

void TOH(lli n, lli a, lli b, lli c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);                         //2 shells can go from a to b using c
        cout << "[" << a << "-" << c << "]" << endl; //print steps for upper ring of the ath to cth
        TOH(n - 1, b, a, c);                         //2 shells can go from b to c using a
    }
}

int main()
{
    lli shells = 3;
    // calling the tower of hanoi function
    TOH(2, 1, 2, 3);
    return 0;
}