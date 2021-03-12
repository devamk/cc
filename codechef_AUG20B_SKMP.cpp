#include <iostream>
#include <string>
using namespace std;

void string_dict(string str, int* arr)
{
    int i=0;
    while (str[i]!= '\0')
    {
        arr[str[i]-'a']++;
        i++;
    }
}
bool check_jump(string str)
{
    int i=1;
    while (str[i]!='\0')
    {
        if (str[i] < str[i-1])
            return (false);
        else if (str[i] > str[i-1])
            return (true);
        i++;
    }
    return (true);
}

void arr_diff(int* str_arr, int* pat_arr)
{
    for (int i=0 ; i<26 ; i++)
    {
        str_arr[i] = str_arr[i] - pat_arr[i];
    }
}

int main() {
	// your code goes here
	
	int T;
	cin >> T;
	while (T-- > 0)
	{
	    string str, pat;
	    cin >> str >> pat;
	    
	    int str_arr[26], pat_arr[26];
	    for (int i=0; i<26 ; i++)
	    {
	        str_arr[i]=0;
	        pat_arr[i]=0;
	    }
	    
	    string_dict(str, str_arr);
	    string_dict(pat, pat_arr);
	    
	    arr_diff(str_arr, pat_arr);
	    
	    
	    if (check_jump(pat))
	    {
	        for (int write_i = 0 ; write_i < 26 ; write_i ++)
	        {
	            if (write_i == pat[0]-'a' + 1)
	            {
	                cout << pat;
	               // printf ("%s",pat);
	            }
	            while (str_arr[write_i] > 0)
	            {
	                printf ("%c",write_i+'a');
	                str_arr[write_i]--;
	            }
	        }
	    }else
	    {
	        for (int write_i = 0 ; write_i < 26 ; write_i++)
	        {
	            if (write_i == pat[0]-'a')
	            {
	                cout << pat;
	               // printf ("%s",pat);
	            }
	            while (str_arr[write_i] > 0)
	            {
	                printf ("%c",write_i+'a');
	                str_arr[write_i]--;
	            }
	        }
	    }
	    printf ("\n");
	}
	return 0;
}
