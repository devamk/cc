#include <iostream>
using namespace std;


int num_digits(int num)
{
    int rem = num % 9;
    int to_ret = num/9;
    if (rem > 0)
    {
        to_ret++;
    }
    return (to_ret);
}
int main() {
	int T;
	cin >> T;
	while (T-- > 0)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    n1 = num_digits(n1);
	    n2 = num_digits(n2);
	    
	    if (n1 < n2)
	    {
	        cout <<"0 ";
	    }else
	    {
	        cout << "1 ";
	    }
	    cout << min(n1,n2) << endl;
	    
	    
	}
	return 0;
}
