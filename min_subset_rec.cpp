#include <iostream>
#include <stdlib.h>
using namespace std;
int soln(int* arr, int i, int pres_sum, int total, int len){
    if (i!=len){
        int res1 = soln(arr, i+1, pres_sum+arr[i],total,len),
            res2 = soln(arr, i+1, pres_sum,total,len);
        
        if ((res1)<=res2){
            return res1;
        }else{
            return res2;
        }
    }else{
        return (abs((2*pres_sum)-total));
    }
    
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
	        cin >> arr[i];
	        sum = sum+arr[i];
	    }
	    cout << soln(arr,0,0,sum,n)<<endl;
	}
	return 0;
}