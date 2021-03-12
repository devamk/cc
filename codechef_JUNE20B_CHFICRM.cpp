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
        cin >> N;
        int arr[N];
        for (int i =0 ; i<N ; i++)
        {
            cin >> arr[i];
        }


        int count_5 = 0 , count_10 = 0, count_15 = 0;

        bool doable = true;
        for (int i =0 ; i<N ; i++)
        {
            int temp;
            temp = arr[i];
            // cout << temp << "|||" << i << endl;
            if (temp == 5)
            {
                count_5++;
            }else if (temp == 10)
            {   
                count_10++;
                count_5--;
                if (count_5 < 0)
                {
                    doable = false;
                    // cout << "no 5" << i <<endl;
                    break;
                }
            }else
            {
                count_15 ++;

                if (count_10 > 0)
                {
                    count_10--;
                }else if (count_5 >= 2)
                {
                    count_5 = count_5 - 2;
                }else
                {
                    // cout << "no ---" << count_5 << count_10 <<endl;
                    doable = false;
                    break;
                }
            }
            
        }

        if (doable)
        {
            cout << "YES" << endl;
        }else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}