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
int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = x * a + y * b;
    for (int i = 1; i <= 100000; i++)
    {
        int price = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, price);
    }
    cout << ans;
    return 0;
}