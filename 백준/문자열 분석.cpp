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

	string s="1";
	

	while (1)
	{
		int so = 0;
		int dae = 0;
		int num = 0;
		int space = 0;
		cin.ignore(NULL);
		getline(cin, s);
		if (s == "")
			break;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				dae++;
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				so++;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				num++;
			}
			else if (s[i] == ' ')
			{
				space++;
			}
		}
		cout << so << ' ' << dae << ' ' << num << ' ' << space << '\n';
	}
	return 0;

}