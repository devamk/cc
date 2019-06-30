#include <iostream>
#include <stdlib.h>
using namespace std;
int soln(int* arr,  int total_sum, int len){
// shall generate a [max_sum+1][arr_length+1] matrix and see all the summation possible
    
    int **mat = (int**)malloc((total_sum+1)*sizeof(int*));
    int *master_sum=(int*)malloc(sizeof(int)*(total_sum+1));//if sum=i is possible then arr[i]=1 o/w 0
    for (int i=0;i<=total_sum;i++){
        master_sum[i]=0;
        mat[i]=(int*) malloc((len+1)*sizeof(int));
        mat[i][0]=0;//sum=i is not possible with atmost 0th element!
    }
    
    master_sum[0]=1;//sum=0 is possible with atmost 0th element!
    
    for (int i=1;i<=len;i++)
    {
        mat[0][i]=1; //sum 0 is possible with atmost any ith elements
    }
    

    for (int pres_sum=1; pres_sum<=total_sum; pres_sum++)
    {
        bool sum_possible=false;
        for (int elem_i=1; elem_i<=len; elem_i++)
        {
            if (mat[pres_sum][elem_i-1]==1 || sum_possible){
                sum_possible=true;
                mat[pres_sum][elem_i]=1;
            }else if (pres_sum-arr[elem_i-1]>=0 && mat[pres_sum-arr[elem_i-1]][elem_i-1]==1)
            {
                sum_possible=true;
                mat[pres_sum][elem_i]=1;
            }
            
        }
        if (sum_possible)
        {
            master_sum[pres_sum]=1;
        }
    }

    cout << "hello" << endl;
//Transversing the last column to see all the sums possible
    int min_sum=total_sum,im;
    for (int i=0; i<=total_sum; i++)
    {
        if (master_sum[i] && abs(total_sum-(2*i))<=min_sum)
        {
            min_sum=abs(total_sum-(2*i));
        }
    }
    
    
    return min_sum;
}

int main() {
	//code
	int N;
	cin >> N;
	while ((N--)>0){
	    int n;
	    cin >> n;
	    int arr[n];
	    int sum=0;
	    for (int i=0;i<n;i++){
	        int read_i;
            cin >> read_i;
            arr[i]=read_i;
	        sum = sum+arr[i];
            
	    }
        cout << soln(arr,sum,n)<<endl;
	}
	return 0;
}
