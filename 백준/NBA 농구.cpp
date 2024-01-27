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
	int N, team, min, sec, s, total_1 = 0, total_2 = 0, score_1 = 0, score_2 = 0;
	string t;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		cin >> team >> t;
		min = stoi(t.substr(0, 2));
		sec = stoi(t.substr(3, 2));

		if (score_1 > score_2) 
		{
			total_1 = total_1 + (min * 60) + sec - s;
		}
		else if (score_1 < score_2) 
		{
			total_2 = total_2 + (min * 60) + sec - s;
		}
		if (team == 1) 
			score_1++;
		else 
			score_2++;
		s = (min * 60) + sec;
	}

	if (score_1 > score_2) 
		total_1 = total_1 + (48 * 60) - s;
	else if (score_1 < score_2)
		total_2 = total_2 + (48 * 60) - s;

	printf("%02d:%02d\n", total_1 / 60, total_1 % 60);
	printf("%02d:%02d\n", total_2 / 60, total_2 % 60);
	return 0;

	return 0;
}