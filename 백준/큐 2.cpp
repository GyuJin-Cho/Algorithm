#include<iostream>
#include<queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int N;
	cin >> N;

	string order;
	int Num;
	deque<int> q;
	for(int i=0;i<N;i++)
	{
		cin >> order;

		if(order=="push")
		{
			cin >> Num;
			q.push_back(Num);
		}
		else if(order == "pop")
		{
			if (q.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (order == "size")
		{
			cout << q.size() << '\n';

		}
		else if (order == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (order == "front")
		{
			if (q.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (order == "back")
		{
			if (q.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
	}

	return 0;
}