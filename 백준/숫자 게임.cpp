#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
	if(p1.second==p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int,int>> number;
	int cnt = 1;
	while(N--)
	{
		vector<int> v(5);
		for(int i=0;i<5;i++)
		{
			cin >> v[i];
		}
		int sum = 0;
		string s = "";
		int Max = -2174000;
		for(int i=0;i<v.size();i++)
		{
			for(int j=i+1;j<v.size();j++)
			{
				for(int z=j+1;z<v.size();z++)
				{
					sum = v[i] + v[j] + v[z];
					s = to_string(sum);
					int digit = s[s.size() - 1] - 48;
					Max = max(Max, digit);
				}
			}
		}
		number.push_back({ cnt,Max });
		cnt++;
	}
	sort(number.begin(), number.end(),cmp);
	cout << number[number.size() - 1].first;
	return 0;
}