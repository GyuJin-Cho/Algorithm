#include<iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;

int answer = 0;

void BFS(string begin, string target, vector<string> words)
{
    int N = words.size();
    int M = begin.size();
    vector<int> visit(N, 0);
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    int diff;
    while(!q.empty())
    {
        string start = q.front().first;
        int count = q.front().second;
        q.pop();
        for(int i=0;i<N;i++)
        {
            diff = 0;
            if(visit[i]!=0)
            {
                continue;
            }
            for(int j=0;j<M;j++)
            {
                if (start[j] != words[i][j])
                    diff++;
            }
            if (diff == 1)
            {
                if (words[i] == target)
                {
                    answer = count + 1;
                    return;
                }
                visit[i] = 1;
                q.push(make_pair(words[i], count + 1));
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    bool check = false;
    for(int i=0;i<words.size();i++)
    {
        if (target == words[i])
            check = true;
    }
    if (!check)
        return 0;
    BFS(begin, target, words);
    return answer;
}

int main()
{
    vector<string> v = { "hot", "dot", "dog", "lot", "log", "cog" };
    cout << solution("hit", "cog", v);
	return 0;
}