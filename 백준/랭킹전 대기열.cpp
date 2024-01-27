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

class UserInfo
{
public:
	int Level;
	string Nick;
	UserInfo(int L, string N) : Level(L), Nick(N) {}
	UserInfo() : Level(0), Nick("") {}
};

bool cmp(UserInfo u1, UserInfo u2)
{
	return u1.Nick < u2.Nick;
}


class RoomInfo
{
public:
	int LevelSizeMin;
	int LevelSizeMax;
	vector<UserInfo> User;
	RoomInfo(int L, string N, int LM, int LMA) :LevelSizeMin(LM),LevelSizeMax(LMA)
	{
		User.push_back(UserInfo(L, N));
	}
	RoomInfo() :  LevelSizeMin(0), LevelSizeMax(0) {}
	int GetSize()
	{
		return User.size();
	}
	void Add(int L, string N)
	{
		User.push_back(UserInfo(L, N));
	}

	void Sorting()
	{
		sort(User.begin(), User.end(),cmp);
	}

	~RoomInfo() {}
};


int main()
{
	int n, m;
	cin >> n >> m;
	vector<RoomInfo> v;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		string nick;
		cin >> num >> nick;
		if (v.empty())
		{
			v.push_back(RoomInfo(num, nick, num - 10, num + 10));
		}
		else
		{
			bool ch = false;
			for (int j = 0; j < v.size(); j++)
			{
				if (v[j].GetSize() == m)
					continue;
				if (v[j].LevelSizeMin > num || v[j].LevelSizeMax < num)
					continue;
				v[j].Add(num, nick);
				ch = true;
				break;
			}
			if (!ch)
			{
				v.push_back(RoomInfo(num, nick, num - 10, num + 10));
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		v[i].Sorting();
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].GetSize() == m)
			cout << "Started!" << '\n';
		else
			cout << "Waiting!" << '\n';
		for (int j = 0; j < v[i].User.size(); j++)
		{
			cout << v[i].User[j].Level << ' ' << v[i].User[j].Nick << '\n';
		}
	}
	return 0;
}