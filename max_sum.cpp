#include <iostream>
#include <chrono>
#include <unistd.h>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int k;
    for (k = 1; k*(k+1)<=2*N ; k++);
    cout << k-1 << endl;
    
    for (int i=1; i<=k-1 ; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    
}