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
        int N;
        string str;
        cin >> str;
        N = str.size();
        if (N<=1)
        {
            cout << 0 << endl;
            continue;
        }

        int* arr = (int*) malloc(sizeof(int)*str.size());

        arr[0] = 0;
        
        if (str[1] == str[0])
        {
            arr[1] = 0;
        }else
        {
            arr[1] = 1;
        }
        
        for (int i=2 ; i<str.size() ; i++)
        {
            if (str[i] == str[i-1])
            {
                arr[i] = arr[i-1];
            }else
            {
                arr[i] = max(arr[i-1], arr[i-2] + 1);
            }    
        }

        cout << arr[N-1] << endl;    
    }

    return 0;
}