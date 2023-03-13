#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

bool cmd(pair<char,int> p1, pair<char,int> p2)
{
	return p1.second> p2.second;
}

int main()
{
	int N;
	cin >> N;
	
	cin.ignore();
	for(int i=0;i<N;i++)
	{
		vector<pair<char, int>>v(26);
		string s;
		getline(cin, s);
		for(int j=0;j<s.size();j++)
		{
			if (s[j] == ' ')
				continue;
			v[s[j] - 'a'].first = s[j];
			v[s[j] - 'a'].second++;
		}

		sort(v.begin(), v.end(),cmd);

		if(v[0].second!=v[1].second)
		{
			cout << v[0].first << '\n';
		}
		else if(v[0].second == v[1].second)
		{
			cout << "?" << '\n';
		}
		
	}

	
	return 0;
}