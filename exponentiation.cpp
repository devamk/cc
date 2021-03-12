#include <iostream>
#include <chrono>
#include <unistd.h>
#include <map>
#include <iterator>
#include <vector>
#include <string>

using namespace std;
int g_count = 0;
long long int power(int num, int pow, map <int, long long int> &mp);
void print_mp(map <int, long long int> &dict);


long long int power(int num, int pow, map <int, long long int> &mp)
{
    cout << "g_count="<< ++g_count << "||power=" << pow <<"||"<<endl;
    // print_mp (mp);
    if (pow == 0 || pow == 1)
    {
        return (mp[pow]);
    }
    

    if (mp.find(pow) == mp.end())
    {
        int left = pow / 2;
        int right = pow - left;
        cout << "left=" << left << "||" << "right=" << right <<endl;
        if (mp.find(left) == mp.end())
        {
            long long int left_pow = power(num, left, mp);
            cout << "left_pow=" << left_pow<<endl;
            mp.insert(pair<int, long long int>(left,left_pow));
        }

        if (mp.find(right) == mp.end())
        {
            long long int right_pow = power(num, right, mp);
            cout << "right_pow=" << right_pow<<endl;
            mp.insert(pair<int, long long int>(right,right_pow));
            // print_mp(mp);
        }

        mp.insert(pair<int, long long int>(pow, (mp[right]*mp[left])));
        return(mp[pow]);

    }else{

        return (mp[pow]);
    
    }
}


void print_mp(map <int, long long int> &dict)
{
    map <int, long long int> :: iterator itr;
    for (itr = dict.begin(); itr != dict.end(); itr++)
    {
        cout << itr->first << "=" << itr->second <<"||||";
    }
    cout << endl;
}
    
long long int pow1 (int n, int pow)
{
    // cout << "g_count="<< ++g_count << endl; 
    if (pow == 0)
    {
        return (1);
    }

    if (pow == 1)
    {
        return (n);
    }

    int left = pow/2;
    int right = pow - left;

    long long int half_pow = pow1 (n, left);
    long long int half_pow2 = pow1 (n, right);
    cout << "g_count="<< ++g_count << endl;
    return (half_pow * half_pow2);

    // if (left == right)
    // {
    //     long long int half_pow = pow1 (n, left);
    //     return (half_pow * half_pow);
    // }else
    // {
    //     long long int half_pow = pow1 (n, left);
    //     return (half_pow * half_pow * a);
    // }
    
} 
using namespace std;
int main()
{
    map <int, long long int> dict;
    dict[0] = 1;
    dict[1] = 2;
    // for (int i = 0 ; )
    cout << pow1(2, 30) << endl;
    print_mp(dict);

}

