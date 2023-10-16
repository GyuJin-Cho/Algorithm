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
const int COUNT = 9;
int main()
{
	vector<int> v(COUNT);
	int cc = 0;
	for(int i=0;i<COUNT;i++)
	{
		cin >> v[i];
		cc += v[i];
	}

	

	sort(v.begin(), v.end());
	for(int i=0;i<COUNT-1;i++)
	{
		for(int j=i+1;j<COUNT;j++)
		{
			if(cc-v[i]-v[j]==100)
			{
				for(int k=0;k<COUNT;k++)
				{
					if(v[k]!=v[i]&&v[k]!=v[j])
					{
						cout << v[k] << '\n';
					}
				}
				exit(0);
			}
		}
	}

	return 0;
}