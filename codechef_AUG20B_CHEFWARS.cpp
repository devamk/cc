#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while ((T--) > 0)
    {
        int P, H;
        cin >> H >> P;
        while (P>0 && H>0)
        {
            H = H - P;
            P = P/2;
        }
        if (H>0)
        {
            cout << 0 << endl;
        }else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}