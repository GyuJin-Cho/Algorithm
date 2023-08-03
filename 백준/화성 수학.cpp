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
	float a;
	string s;
	while (T--)
	{
		cin >> a;
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '@')
			{
				a *= 3;
			}
			else if (s[i] == '%')
			{
				a += 5;
			}
			else if(s[i]=='#')
			{
				a -= 7;
			}
		}
		printf("%.2f\n", a);
	}

	return 0;
}