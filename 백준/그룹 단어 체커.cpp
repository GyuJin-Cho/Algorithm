#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		bool check = true;
		string a;
		cin >> a;
		map<char, int> m;
		for (int j = 0; j < a.size();j++)
		{
			if(m[a[j]]==0)
			{
				m[a[j]]++;
			}
			else
			{
				if(a[j]!=a[j-1])
				{
					check = false;
					break;
				}
			}
		}
		if (!check)
			continue;
		cnt++;
	}
	cout << cnt;
	return 0;
}