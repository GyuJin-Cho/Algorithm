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

int a[101];
int d[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
    }
    d[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j <= m; j++)
        {
            if (j - a[i] >= 0) 
            {
                d[j] += d[j - a[i]];
            }
        }
    }
    cout << d[m];
    return 0;
}