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

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> d(n);
    vector<int> d2(n);
    for (int i = 0; i < n; i++)
    {
        d[i] = a[i];
        if (i == 0) 
            continue;
        if (d[i] < d[i - 1] + a[i]) 
        {
            d[i] = d[i - 1] + a[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        d2[i] = a[i];
        if (i == n - 1)
            continue;
        if (d2[i] < d2[i + 1] + a[i]) 
        {
            d2[i] = d2[i + 1] + a[i];
        }
    }
    int ans = d[0];
    for (int i = 1; i < n; i++) 
    {
        if (ans < d[i]) 
        {
            ans = d[i];
        }
    }
    for (int i = 1; i < n - 1; i++) 
    {
        if (ans < d[i - 1] + d2[i + 1]) 
        {
            ans = d[i - 1] + d2[i + 1];
        }
    }
    cout << ans;
    return 0;
}