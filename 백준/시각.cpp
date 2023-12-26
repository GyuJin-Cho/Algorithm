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

	int N, K, num = 0;

	cin >> N >> K;

	for (int hour = 0; hour <= N; hour++) 
	{
		for (int minute = 0; minute < 60; minute++) 
		{
			for (int sec = 0; sec < 60; sec++)
			{
				if (hour % 10 == K || hour / 10 == K ||
					minute % 10 == K || minute / 10 == K ||
					sec % 10 == K || sec / 10 == K)
					num++;
			}
		}
	}

	cout << num;
}