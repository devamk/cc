#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d",&N);
    int *input=(int*)malloc(sizeof(int)*N), max=-1;
    
    for (int i=0;i<N;i++)
    {
        scanf("%d",&input[i]);
        if (input[i]>max)
        {
            max=input[i];
        }
    }
    if(max<=5)
    {
        for (int i; i<N ; i++)
        {
            printf ("%d\n",input[i]);
        }

    }else
    {
        /* code */
        long int  *arr = (long int*) malloc(sizeof(long int)*(max));
        arr[0]=1;
        arr[1]=2;
        arr[2]=3;
        arr[3]=4;
        arr[4]=5;
        int mult2=2,mult3=1,mult5=2;
        for (int i=5; i<max; i++)
        {
            long int val2, val3, val5;
            val2=arr[mult2]*2;
            val3=arr[mult3]*3;
            val5=arr[mult5]*5;
            if (val2<=val3)
            {
                if (val2<=val5)
                {
                    arr[i]=(long int)val2;
                    mult2++;
                }else
                {
                    arr[i]=(long int)val5;
                    mult5++;
                }
            }else
            {
                if (val3<=val5)
                {
                    arr[i]=(long int)val3;
                    mult3++;
                }else
                {
                    arr[i]=(long int)val5;
                    mult5++;
                }
            }
            while (mult2<=i && 2*arr[mult2]<=arr[i])
            {
                mult2++;
            }
            while (mult3<=i && 3*arr[mult3]<=arr[i])
            {
                mult3++;
            }
            while (mult5<=i && 5*arr[mult5]<=arr[i])
            {
                mult5++;
            }
            
        }
        for (int i=0; i<N; i++)
        {
            printf ("%ld\n",arr[input[i]-1]);
        }
        free(arr);
    }
    
    
	return 0;
}