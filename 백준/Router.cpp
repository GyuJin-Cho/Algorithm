#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int Size = 0;
	cin >> Size;
	int a;
	queue<int> q;
	while(1)
	{
		cin >> a;
		if (a == -1)
			break;
		if(a==0)
		{
			if(!q.empty())
				q.pop();
		}
		else
		{
			if(q.size()==Size)
			{
				continue;
			}
			else
			{
				q.push(a);
			}
		}
	}

	if (q.empty())
		cout << "empty";
	else
	{
		while(!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
	}

	return 0;
}