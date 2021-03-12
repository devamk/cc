#include <iostream>
#include <chrono>
#include <unistd.h>
#include <map>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

void transpose(int N, int **arr)
{
    ///// transpose
    for (int i = 0 ; i <= N-1 ; i++)
    {
        for (int j = 0 ; j <= i ; j++)
        {
            int temp;
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

}

void reflection(int N, int **arr)
{
    ////// mirror image
    if (N%2 != 0)
    {
        for (int i = 0 ; i < N ; i++)
        {
            for (int j = 0; j < N/2 ; j++)
            {
                int temp;
                temp = arr[i][j];
                arr[i][j] = arr[i][N-1-j];
                arr[i][N-1-j] = temp;
            }
        }
    }else
    {
        for (int i = 0 ; i < N ; i++)
        {
            for (int j = 0; j <= (N/2)-1 ; j++)
            {
                int temp;
                temp = arr[j][i];
                arr[j][i] = arr[N-1-j][i];
                arr[N-1-j][i] = temp;
            }
        }
    }

}


int main()
{
    int N, temp;
    int **arr;
    
    cin >> N;
    arr = (int**) malloc(sizeof(int*)*N);

    for (int i = 0 ; i < N ; i++)
    {
        arr[i] = (int*) malloc(sizeof(int)*N);
        for (int j = 0 ; j < N ; j++)
        {
            cin >> temp;
            arr[i][j] = temp;
        }
    }

    transpose(N,arr);
    reflection(N, arr);

    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            printf ("%d ", arr[i][j]);
            // cout <<  << " ";
        }
        printf ("\n");
    }   

}