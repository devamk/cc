#include <iostream>
#include <chrono>
#include <unistd.h>
#include <map>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

void swap (int* arr, int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
    return;
}

bool comp(int n1, int n2)
{
    return (n1 < n2);
}

int find_k_naive(int* arr, int k, int size)
{
    sort(arr, arr+size, comp);
    return (arr[k-1]);
}


int select_k (int *arr, int start, int end, int k)
{
    cout << "start=" << start << "||" << "end=" << end << "||finding=" << k;
    int size = end-start+1;
    if (k > size || k <= 0)
    {
        return (-1);
    }
    if (size == 1)
    {
        return (arr[start]);
    }

    swap(arr, end, rand()%size+start);

    int i = start, j = end-1;
    while (i <= j)
    {
        if (arr[i] <= arr[end])
        {
            i++;
        }else
        {
            swap(arr, i, j);
            j--;
        }
    }

    swap(arr, i, end);
    cout << "||pivot=" << i << endl;
    
    if ((i-start+1) == k)
    {
        return (arr[i]);
    }else
    {
        if ((i-start+1) < k)
        {
            return (select_k(arr, i, end, k-i+start));
        }else
        {
            return (select_k(arr, start, i, k));
        }
       
    }
    

}

int find_k (int *arr, int k, int size)
{
    int k_elem = select_k (arr, 0, size-1, k);
    return (k_elem);

}



int main(int argc, char** argv)
{
    int arr[] = {1,2,3,4,5,6,7,8,143,10,11,12,13};


    cout << find_k(arr, atoi(argv[1]), 13);
}