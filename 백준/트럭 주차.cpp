#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> Time;
int A, B, C;
int s, e;
int Start, End;
int answer = 0;
void P()
{
	int i = 1;
	int count = 0;
	while (i != End+1)
	{
		switch (count)
		{
			case 1:
			{
				answer += A * count;
				break;
			}
			case 2:
			{
				answer += B * count;
				break;
			}
			case 3:
			{
				answer += C * count;
				break;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			if (Time[j].first == i)
			{
				count++;
			}
			else if (Time[j].second == i)
			{
				count--;
			}
		}
		i++;
	}
	
}

int main()
{
	
	cin >> A >> B >> C;
	Start = 999999999;
	End = -1;
	for (int i = 0; i < 3; i++)
	{
		cin >> s >> e;
		Time.push_back(make_pair(s, e));

		Start = min(s, Start);
		End = max(e, End);
	}

	P();
	cout << answer;
	return 0;
}