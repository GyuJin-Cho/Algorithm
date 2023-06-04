#include <algorithm>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class Photo
{
public:
	int Time;
	int Vote;

public:
	Photo(int time = 0, int vote = 0)
	{
		this->Time = time;
		this->Vote = vote;
	}
};

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<int> v(M);
	unordered_map<int, Photo> Photos;
	for (int i = 0; i < M; i++)
	{
		cin >> v[i];
		int size = Photos.size();
		if (size == N)
		{
			if (Photos.find(v[i]) == Photos.end())
			{
				int cntMin = 2174000;
				int Min = 2174000;
				int key = 0;
				for (auto i : Photos)
				{
					if (i.second.Vote < cntMin)
					{
						cntMin = i.second.Vote;
					}
				}
				for (auto i : Photos)
				{
					if (i.second.Vote <= cntMin && i.second.Time < Min)
					{
						Min = min(Min, i.second.Time);
						key = i.first;
					}
				}
				unordered_map<int, Photo>::iterator iter;
				iter = Photos.find(key);
				Photos.erase(iter);
			}
		}
		if (Photos.find(v[i]) != Photos.end())
		{
			Photo p(Photos[v[i]].Time, Photos[v[i]].Vote + 1);
			Photos[v[i]] = p;
		}
		else
		{
			Photo p(i, Photos[v[i]].Vote + 1);
			Photos[v[i]] = p;
		}
	}
	
	set<int> ans;
	for (auto i : Photos)
		ans.insert(i.first);
	for (int i : ans)
		cout << i << ' ';
	return 0;
}