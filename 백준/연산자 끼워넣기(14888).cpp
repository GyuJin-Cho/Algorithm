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
long long Min = 1e12;
long long Max = -1e12;
int main()
{
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	vector<int> caculnum(4);
	for(int i=0;i<4;i++)
	{
		cin >> caculnum[i];
	}
	char c[] = { '+','-','*','/' };
	vector<char> cacul;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<caculnum[i];j++)
		{
			cacul.push_back(c[i]);
		}
	}

	sort(cacul.begin(), cacul.end());


	do
	{
		long long caculation = 0;
		bool check = false;
		for(int i=0;i<cacul.size();i++)
		{
			if(cacul[i]=='+')
			{
				if(!check)
				{
					caculation = num[i] + num[i + 1];
					check = true;
				}
				else
				{
					caculation += num[i + 1];
				}
			}
			else if (cacul[i] == '-')
			{
				if (!check)
				{
					caculation = num[i] - num[i + 1];
					check = true;
				}
				else
				{
					caculation -= num[i + 1];
				}
			}
			if (cacul[i] == '*')
			{
				if (!check)
				{
					caculation = num[i] * num[i + 1];
					check = true;
				}
				else
				{
					caculation *= num[i + 1];
				}
			}
			if (cacul[i] == '/')
			{
				if (!check)
				{
					caculation = num[i] / num[i + 1];
					check = true;
				}
				else
				{
					caculation /= num[i + 1];
				}
			}
		}
		Min = min(caculation, Min);
		Max = max(caculation, Max);

	} while (next_permutation(cacul.begin(), cacul.end()));
	cout << Max << '\n' << Min;
	return 0;
}