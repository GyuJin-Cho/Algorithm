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
bool ch[101][101];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

vector<int> Curve(const int& x, const int& y, const int& dir, const int& gen)
{
	vector<int> answer = { dir };
	for (int i = 1; i <= gen; i++)
	{
		vector<int> temp(answer);
		reverse(temp.begin(), temp.end());
		for (int& j : temp)
		{
			j = (j + 1) % 4;
		}
		answer.insert(answer.end(), temp.begin(), temp.end());
	}
	return answer;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x, y, dir, gen;
		cin >> y >> x >> dir >> gen;
		vector<int> dirs = Curve(x, y, dir, gen);
		ch[x][y] = true;
		for (int d : dirs)
		{
			x += dx[d];
			y += dy[d];
			ch[x][y] = true;
		}
	}
	int answer = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (ch[i][j] && ch[i][j + 1] && ch[i + 1][j] && ch[i + 1][j + 1])
			{
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}