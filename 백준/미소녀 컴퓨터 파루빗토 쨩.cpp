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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	char op;
	bool ch = false;
	string left, right;
	for (int i = 0; i < s.length(); i++)
	{
		if (i > 0  && (s[i] == '+' || s[i] == '-' || s[i] == '*'||s[i]=='/')&&!ch)
		{
			op = s[i];
			ch = true;
			continue;
		}
		if (!ch)
			left += s[i];
		else
			right += s[i];
	}

	long long leftnum = 0, rightnum = 0, ans = 0;

	if(op=='/')
		if (right == "0")
		{
			cout << "invalid";
			return 0;
		}
	bool frontminus = false;
	int sqr = left.size()-1;
	for (int i = 0; i < left.size(); i++)
	{
		if (left[i] == '-')
		{
			frontminus = true;
			sqr--;
			continue;
		}
		leftnum += (left[i] - 48) * pow(8, sqr);
		sqr--;
	}
	if (frontminus)
		leftnum =  (-leftnum);

	sqr = right.size() - 1;
	frontminus = false;
	for (int i = 0; i < right.size(); i++)
	{
		if (right[i] == '-')
		{
			frontminus = true;
			sqr--;
			continue;
		}
		rightnum += (right[i] - 48) * pow(8, sqr);
		sqr--;
	}

	if (frontminus)
		rightnum = (-rightnum);
	long long tmp = 0;
	if (op == '+')
		ans = leftnum + rightnum;
	else if (op == '-')
		ans = leftnum - rightnum;
	else if (op == '*')
		ans = leftnum * rightnum;
	else
	{
		double tmpd = double(leftnum) / double(rightnum);
		if (tmpd > 0)
		{
			ans = floor(tmpd);
		}
		else
		{
			ans = floor(tmpd);
		}
	}
	if (ans < 0)
	{
		ans = -ans;
		cout << "-" << oct << ans;
	}
	else
	{
		cout << oct << ans;
	}
	return 0;
}