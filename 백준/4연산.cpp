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
const unsigned long long MAXINDEX = 1000000001;
using namespace std;
long long n, m;
char ca[] = { '*','+','-','/' };
vector<string> v;
class node
{
public:
	long long result;
	string s;
	node(unsigned long long r, string s) : result(r), s(s) {}
	node() : result(0), s("") {}
};
void BFS()
{
	queue<node> q;
	q.push(node(n, ""));
	set<long long> ch;
	ch.insert(n);
	while (!q.empty())
	{
		node no = q.front();
		q.pop();
		if (no.result == m)
		{
			cout << no.s;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (ca[i] == '+')
			{
				long long nresult = no.result + no.result;
				if (nresult < MAXINDEX && nresult >= 0 && ch.count(nresult) == 0)
				{
					q.push(node(nresult, no.s + '+'));
					ch.insert(nresult);
				}
			}
			else if (ca[i] == '-')
			{
				long long nresult = no.result - no.result;
				if (nresult < MAXINDEX && nresult >= 0 && ch.count(nresult) == 0)
				{
					q.push(node(nresult, no.s + '-'));
					ch.insert(nresult);
				}
			}
			else if (ca[i] == '*')
			{
				long long nresult = no.result * no.result;
				if (nresult < MAXINDEX && nresult >= 0 && ch.count(nresult) == 0)
				{
					q.push(node(nresult, no.s + '*'));
					ch.insert(nresult);
				}
			}
			else if (ca[i] == '/')
			{
				if (no.result == 0)
					continue;
				unsigned long long nresult = no.result / no.result;
				if (nresult < MAXINDEX && nresult >= 0 && ch.count(nresult) == 0)
				{
					q.push(node(nresult, no.s + '/'));
					ch.insert(nresult);
				}
			}
		}
	}
	cout << -1;
}

int main()
{
	cin >> n >> m;
	if (n == m)
	{
		cout << 0;
		return 0;
	}
	BFS();


	return 0;
}