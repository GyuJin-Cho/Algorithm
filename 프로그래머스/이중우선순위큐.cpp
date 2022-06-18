#include<iostream>
#include <string>
#include <vector>
#include<queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int> pq;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i].find('I') != string::npos)
        {
            string temp="";
            for (int j = 2; j < operations[i].size(); j++)
            {
                temp += operations[i][j];
            }
            pq.push(atoi(temp.c_str()));
        }
        if (operations[i].find('D') != string::npos)
        {
            string temp = "";
            for (int j = 2; j < operations[i].size(); j++)
            {
                temp += operations[i][j];
            }
            if (atoi(temp.c_str()) == 1)
            {
                if (!pq.empty())
                {
                    pq.pop();
                }
            }
            else
            {
                if (!pq.empty())
                {
                    priority_queue<int> change;
                    int size = pq.size();
                    for (int j = 0; j < size; j++)
                    {
                        if (j == size -1)
                        {
                            pq.pop();
                        }
                        else
                        {
                            change.push(pq.top());
                            pq.pop();
                        }
                    }
                    pq = change;
                }
            }
        }
    }

    if (pq.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else
    {
        int Max = pq.top();
        answer.push_back(Max);
        int size = pq.size();
        for (int j = 0; j < size; j++)
        {
            if (j == size -1)
            {
                int Min = pq.top();
                answer.push_back(Min);
            }
            else
            {
                pq.pop();
            }
            
        }
        return answer;
    }
    
}

int main()
{
    vector<string> op = { "I 7","I 5","I -5","D -1" };
    vector<int> ans = solution(op);

    for (auto i : ans)
        cout << i;

    return 0;
}