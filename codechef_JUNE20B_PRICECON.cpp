#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while ((T--)>0)
    {
        int N, K, temp=0;
        cin >> N;
        cin >> K;
        long long int res = 0;
        for (int i=0 ; i<N ; i++)
        {
            cin >> temp;
            res = res + max(0, temp-K);
        }
        cout << res << endl;
    }

    return 0;
}