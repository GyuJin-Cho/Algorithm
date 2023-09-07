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
bool check[1501][1501];
int sum;
void DFS (int x,int y)
{
	if (check[x][y])
		return;
	check[x][y] = true;
	int a[3] = { x,y,sum - x - y };
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i]<a[j])
			{
				int b[3] = { x,y,sum - x - y };
				b[i] += a[i];
				b[j] -= a[i];
				DFS(b[0], b[1]);
			}
		}
	}
}
int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	sum = x + y + z;
	if(sum%3!=0)
	{
		cout << 0;
		return 0;
	}
	DFS(x, y);
	if(check[sum/3][sum/3])
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}