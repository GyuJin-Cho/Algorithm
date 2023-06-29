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
char Map[8][8];

int main()
{
	int answer = 0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
		{
			cin >> Map[i][j];
			if ((i + j) % 2 == 0 && Map[i][j] == 'F')
				answer++;
		}
	cout << answer;
	return 0;
}