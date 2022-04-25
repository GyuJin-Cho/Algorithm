#include<iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<char> q;
void QPush(string skill)
{
    while (!q.empty())
        q.pop();

    for (int i = 0; i<skill.length(); i++)
    {
        q.push(skill[i]);
    }
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        QPush(skill);
        string temp = skill_trees[i];
        for (int j = 0; j < skill_trees[i].length(); j++)
        {
            if (skill.find(skill_trees[i][j])!=string::npos)
            {
                if (q.front() == skill_trees[i][j])
                {
                    q.pop();
                    temp.erase(temp.begin(), temp.begin()+1);
                }
                else
                {
                    break;
                }
            }
            else if (skill.find(skill_trees[i][j]) == string::npos)
            {
                temp.erase(temp.begin(), temp.begin()+1);
                continue;
            }
        }
        if (q.empty()||temp.empty())
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> skill_trees = { "CEFD"};

    cout << solution("CBD", skill_trees);

    return 0;
}