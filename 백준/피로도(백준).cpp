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
	int a, b, c, m;
	int num = 0, tired = 0;
	cin >> a >> b >> c >> m;
	for(int i=0;i<24;i++)
	{
		if(tired+a<=m)
		{
			tired += a;
			num++;
		}
		else
		{
			tired -= c;
			if (tired < 0)
				tired = 0;
		}
	}
	cout << num * b;
	return 0;
}