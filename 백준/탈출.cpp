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

queue <int> q, tmp;
int led[100000] = { 0 };
bool visited[100000] = { false };
int x, X, success = -1;
string y;
void Bfs(int N, int G, int T)
{
	while (!q.empty()) 
	{
		if (led[q.front()] > T) 
			break;
		if (q.front() == G) 
		{
			success = led[q.front()];
			break;
		}
		x = q.front() + 1;
		if (x < 100000 && visited[x] == false) 
		{
			visited[x] = true;
			led[x] = led[q.front()] + 1;
			q.push(x);
		}
		x = q.front() * 2;
		y = to_string(x);
		if (y[0] != '0')
			y[0] -= 1;
		X = stoi(y);
		if (x < 100000 && visited[X] == false)
		{
			visited[X] = true;
			led[X] = led[q.front()] + 1;
			q.push(X);
		}
		q.pop();
	}
}

int main()
{
	int N, T, G;
	cin >> N >> T >> G;
	visited[N] = true;
	q.push(N);
	Bfs(N, G, T);
	if (success == -1) 
		cout << "ANG";
	else
		cout << success;
	return 0;
}