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

int main()
{
	int T;
	cin >> T;
	string s;
	while(T--)
	{
		cin >> s;
		int a, b;
		string tmp = "";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==',')
			{
				a = stoi(tmp);
				tmp.clear();
				continue;
			}
			tmp+=s[i];
		}
		b = stoi(tmp);
		cout << a + b << '\n';
	}

	return 0;
}