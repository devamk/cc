#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <tuple>

using namespace std;

bool comparator_func(tuple<int, int> t1, tuple<int, int> t2)
{
    return (get<0>(t1) < get<0>(t2));
}
int main() {


    int N;
    cin >> N;
    int start_i, wait_i;
    
    
    vector <tuple<int, int>> arr;
    for (int i = 0 ; i < N ; i++)
    {
        cin >> start_i >> wait_i;
        arr.push_back(make_tuple(start_i, start_i + wait_i));
    }
    
    sort(arr.begin(), arr.end(), comparator_func);    
    
    
    
    
    
    return 0;
}