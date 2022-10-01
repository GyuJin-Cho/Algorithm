#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string Order;

		cin >> Order;
		int Case;
		cin >> Case;
		string number;
		cin >> number;
		string tmp = "";
		deque<int> dq;
		for (int j = 0; j < number.size(); j++)
		{
			if (number[j] >= '0' && number[j] <= '9')
			{
				tmp += number[j];
			}
			if (number[j] == ',' || number[j] == ']')
			{
				if (tmp.empty())
				{
					dq.clear();
					break;
				}
				dq.push_back(stoi(tmp));
				tmp = "";
			}
		}
		bool check = false;
		bool print = true;
		for (int i = 0; i < Order.size(); i++)
		{
			if (Order[i] == 'R')
			{
				check = !check;
			}
			else
			{
				if (dq.empty())
				{
					cout << "error";
					print = false;
					break;
				}
				else if (check)
				{
					dq.pop_back();
				}
				else
				{
					dq.pop_front();
				}
			}
		}
		if (print)
		{
			
			if (!check)
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
					{
						cout << ",";
					}
				}
				cout << "]";
			}
			else
			{
				cout << "[";
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
					{
						cout << ",";
					}
				}
				cout << "]";
			}
		}
		if (i != T - 1)
			cout << '\n';
	}
	return 0;
}