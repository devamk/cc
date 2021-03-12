#include <iostream>
#include <chrono>
#include <unistd.h>
#include <map>
#include <vector>


using namespace std;


void mat_mult(vector<int>* mat1, vector<int>* mat2, int* res)
{
    res[0] = (mat1[0]*mat2[0])%10 + (mat1[1]*mat2[2])%10;
    res[1] = (mat1[0]*mat2[1])%10 + (mat1[1]*mat2[3])%10;
    res[2] = (mat1[2]*mat2[0])%10 + (mat1[3]*mat2[2])%10;
    res[3] = (mat1[2]*mat2[1])%10 + (mat1[3]*mat2[3])%10;

    return;
}

int calc_fib(long long int n, dict)
{
    dict.push_back(vector<int>(arr, arr+4));
    
    for (long long int i = 2 ; i <= n ; i = i*2)
    {
        mat_mult(dict[i-1], dict[i-1], arr);
        dict.push_back(vector<int>(arr, arr+4));
    } 

    i = i / 2;
    if (i != n)
    {
        n = n - i;

    }else
    {
        return (dict[])
    }
    
}


int main()
{
    vector < vector<int> > dict;
    int arr[] = {1, 1, 1, 0};
    
    int ret = calc_fib(5, &dict);
    cout << ret << endl;
}