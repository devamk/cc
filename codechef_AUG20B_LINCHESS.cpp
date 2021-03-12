#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while ((T--) > 0)
    {
        int min_moves,N, K, to_return=-1;
        cin >> N >> K;
        int arr[N];
        min_moves = K;
        for (int i = 0 ; i<N ; i++)
        {
            cin >> arr[i];
            if (K%arr[i] == 0)
            {
                if (min_moves > (K/arr[i])-1)
                {
                    min_moves = (K/arr[i])-1;
                    to_return = arr[i];
                }
                
            }
        }
        cout << to_return << endl;
    }
    return 0;
}