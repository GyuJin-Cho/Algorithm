#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int arr[] = { 10,20,30,40 };
int Plus = 0;
int emo = 0;
vector<int> v;
void DFS(const vector<vector<int>>& users, const vector<int>& emoticons)
{
	if(v.size()==emoticons.size())
	{
        int PlusTmp = 0;
        int EmoTmp = 0;

        for(int i=0;i<users.size();i++)
        {
            int p = 0;
	        for(int j=0;j<emoticons.size();j++)
	        {
                if (users[i][0] <= v[j])
                {
                    p += emoticons[j] * (100 - v[j]) / 100;
                }
	        }
            if(p>=users[i][1])
            {
                PlusTmp++;
            }
            else
            {
                EmoTmp += p;
            }
        }
        if (Plus < PlusTmp)
        {
            Plus = PlusTmp;
            emo = EmoTmp;
        }
        else if(Plus==PlusTmp && emo<EmoTmp)
        {
            emo = EmoTmp;
        }
        return;
	}
    
    for(int i=0;i<4;i++)
    {
        v.push_back(arr[i]);
        DFS(users, emoticons);
        v.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;

    DFS(users, emoticons);
    answer.push_back(Plus);
    answer.push_back(emo);
    return answer;
}

int main()
{
    vector<vector<int>> u = {{40, 10000},{25,10000}};
    vector<int> emo = { 7000, 9000 };
    vector<int> ans = solution(u, emo);
    for (int i : ans)
        cout << i << ' ';
    return 0;
}