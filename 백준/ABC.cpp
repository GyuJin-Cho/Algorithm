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
bool d[31][31][31][436];
char ans[32];
int n, k;

bool GO(int i, int a,int b, int p)
{
	if(i==n)
	{
		if (p == k)
			return true;
		else
			return false;
	}
	if (d[i][a][b][p])
		return false;
	d[i][a][b][p] = true;
	ans[i] = 'A';
	if (GO(i + 1, a + 1, b, p))
		return true;
	ans[i] = 'B';
	if (GO(i + 1, a, b+1, p+a))
		return true;
	ans[i] = 'C';
	if (GO(i + 1, a, b, p+a+b))
		return true;
	return false;

}

int main()
{
	cin >> n >> k;
	if (GO(0, 0, 0, 0))
		cout << ans;
	else
		cout << -1;

	return 0;
}