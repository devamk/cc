#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while ((T--)>0)
    {
        long long int N;
        cin >> N;
        
        int pow = 0;
        while (N%2==0)
        {
            pow++;
            N = N/2;
        }
        N = N/2;
        cout << N << endl;
    }

    return 0;
}