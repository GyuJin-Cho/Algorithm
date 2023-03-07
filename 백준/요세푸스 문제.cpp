#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	queue<int> q;
	for(int i=1;i<=N;i++)
	{
		q.push(i);
	}

	int c = 1;
	queue<int> tmpq;
	vector<int> v;
	int MaxCount = N * K;
	while(c<=MaxCount)
	{
		if(c%K==0)
		{
			v.push_back(q.front());
			q.pop();
		}
		else
		{
			tmpq.push(q.front());
			q.pop();
		}

		if(q.empty())
		{
			q = tmpq;
			while (!tmpq.empty())
				tmpq.pop();
		}
		c++;
	}

	cout << "<";
	for(int i=0;i<v.size();i++)
	{
		if(i==v.size()-1)
		{
			cout << v[i];
			break;
		}
		cout << v[i] << ", ";
	}
	cout << ">";

	return 0;
}