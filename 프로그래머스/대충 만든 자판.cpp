#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    unordered_map<char, int> um;
	for(int i=0;i<keymap.size();i++)
	{
		for(int j=0;j<keymap[i].length();j++)
		{
			if(um[keymap[i][j]]==0)
			{
				um[keymap[i][j]] = j + 1;
			}
			else if(um[keymap[i][j]]!=0)
			{
				if(um[keymap[i][j]]>j+1)
				{
					um[keymap[i][j]] = j + 1;
				}
			}
		}
	}

	for(int i=0;i<targets.size();i++)
	{
		int cnt = 0;
		bool ch = false;
		for(int j=0;j<targets[i].length();j++)
		{
			if(um[targets[i][j]]==0)
			{
				answer.push_back(-1);
				ch = true;
				break;
			}
			cnt += um[targets[i][j]];
		}
		if(!ch)
			answer.push_back(cnt);
	}

	if (answer.size() == 0)
		answer.push_back(-1);

    return answer;
}

int main()
{
    vector<string> key = { "BC" };
    vector<string> tar = { "AC", "BC" };
    vector<int> ans = solution(key, tar);

    for (int i : ans)
        cout << i << ' ';

    return 0;
}