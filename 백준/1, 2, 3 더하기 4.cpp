#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;
long long d[1000001];
const int limit = 100000;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0)
    d[0] = 1;
    for (int i = 1; i <= limit; i++) 
    {
        if (i - 1 >= 0) 
        {
            d[i] += d[i - 1];
        }
    }
    for (int i = 1; i <= limit; i++) 
    {
        if (i - 2 >= 0)
        {
            d[i] += d[i - 2];
        }
    }
    for (int i = 1; i <= limit; i++) 
    {
        if (i - 3 >= 0) 
        {
            d[i] += d[i - 3];
        }
    }
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}