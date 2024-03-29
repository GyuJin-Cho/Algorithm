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
struct temp
{
	int num;
	int op;
};
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<temp> a(n);
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			a[i] = { s[i] - '0',0 };
		}
		else
		{
			int op = 1;
			if(s[i]=='-')
			{
				op = 2;
			}
			else if(s[i]=='*')
			{
				op = 3;
			}
			a[i] = { 0,op };
		}
	}
	int m = (n - 1) / 2;
	int answer = -214700000;
	for(int i=0;i<(1<<m);i++)
	{
		bool ok = true;
		for(int j=0;j<m-1;j++)
		{
			if((i&(1<<j))>0&&(i&(1<<(j+1)))>0)
			{
				ok = false;
			}
		}
		if(!ok)
			continue;
		vector<temp> b(a);
		for(int j=0;j<m;j++)
		{
			if((i&(1<<j))>0)
			{
				int k = 2 * j + 1;
				if(b[k].op==1)
				{
					b[k - 1].num += b[k + 1].num;
					b[k + 1].num = 0;
				}
				else if(b[k].op==2)
				{

					b[k - 1].num -= b[k + 1].num;
					b[k].op = 1;
					b[k + 1].num = 0;
				}
				else if(b[k].op==3)
				{

					b[k - 1].num *= b[k + 1].num;
					b[k].op = 1;
					b[k + 1].num = 0;
				}
			}
		}
		int res = b[0].num;
		for(int j=0;j<m;j++)
		{
			int k = 2 * j + 1;
			if(b[k].op==1)
			{
				res += b[k + 1].num;
			}
			else if(b[k].op==2)
			{
				res -= b[k + 1].num;
			}
			else if(b[k].op==3)
			{
				res *= b[k + 1].num;
			}
		}
		answer = max(answer, res);
	}
	cout << answer;
	return 0;
}