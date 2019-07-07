#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin >> T;
	while ((T--)>0)
	{
	    int N;
	    cin >> N;
	    if (N<=1)
	    {
	       cout <<1<< endl;
	        
	    }else
	    {
	        long long int *arr = (long long int*) malloc(sizeof(long long int)*(N+1));
	        arr[0]=0LL;
	        arr[1]=1LL;
	        for (int writeI=2;writeI<(N+1);writeI++)
	        {
	            arr[writeI]=(arr[writeI-1]+arr[writeI-2])%(1000000007LL);
	        }
	        printf("%lld\n",arr[N]%(1000000007LL));
	    }
	}
	return 0;
}