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
        int N, K;
        cin >> N >> K;
        unordered_map <int, int> mp;     
        int arr[N];
        for (int i=0 ; i<N ; i++)
        {
            cin >> arr[i];
        }

        int num_tables = 1;
        int num_clashes = 0;
        for (int i=0 ; i<N ; i++)
        {
            if (mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]]=1;
            }else
            {
                num_clashes = max (num_clashes+1,2);
                if (num_clashes > K)
                {
                    // printf ("---%d---\n", i);
                    num_tables++;
                    num_clashes = 0;
                    mp.clear();
                    mp[arr[i]]=1;
                }else
                {
                    mp[arr[i]]=mp[arr[i]]+1;
                }
                
            }
            
        }
        // printf ("num_tb %d\n", num_tables);
        cout << num_clashes + (num_tables*K)<< endl;
    }
    return 0;
}