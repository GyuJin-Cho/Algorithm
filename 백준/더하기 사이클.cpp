#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt = 0;
	if(s=="0")
	{
		cout << 1;
		return 0;
	}
	if (stoi(s) <= 9)
		s += "0";
	
	string ans = s;

	bool onecheck = false;

	while(true)
	{
		if(ans==s&&onecheck)
		{
			break;
		}

		int One = (ans[0] - 48);
		int Two = (ans[1] - 48);

		int tmp = One + Two;
		if(tmp>=10)
		{
			ans = to_string(Two) + to_string(tmp%10);
		}
		else
		{
			ans = to_string(Two) + to_string(tmp);
		}
		cnt++;
		onecheck = true;
	}
	cout << cnt;
	return 0;
}