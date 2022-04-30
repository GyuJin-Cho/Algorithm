#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string>w;
int N;
pair<int, int> Result;

bool LastWordCheck()
{
    int Count = 1;
    for (int i = 1; i < w.size(); i++)
    {
        int q = i + 1;

        if (w[i][0] != w[i - 1][w[i - 1].length() - 1])
        {
            Result.first = i%N+1;
            Result.second = i / N + 1;
            return false;
        }

    }
    return true;
}

bool OverlapCheck()
{
    int Count = 1;
    bool Check = true;
    Result.first = 9999999;
    Result.second = 9999999;
    for (int i = 0; i < w.size(); i++)
    {
        
        Count = 1;
        for (int j = i + 1; j < w.size(); j++)
        {
            int q = j + 1;
            if (w[i] == w[j])
            {
                Result.first = min(j%N+1,Result.first);
                Result.second = min(j / N + 1, Result.second);
                Check = false;
            }
        }
    }
    if (!Check)
        return Check;

    return true;
}

bool OneWordCheck()
{
    for (int i = 0; i < w.size(); i++)
    {
        if (w[i].length() == 1)
            return false;
    }
    return true;
}

vector<int> solution(int n, vector<string> words) 
{
    vector<int> answer;
    vector<int> Last(2,0);
    vector<int> Overlap(2,0);
    w = words;
    N = n;

    if (!LastWordCheck())
    {
        Last[0]=Result.first;
        Last[1]=Result.second;
    }

    if (!OverlapCheck())
    {
        Overlap[0]=Result.first;
        Overlap[1]=Result.second;
    }

    if (Last[1] > Overlap[1] && Last[1]!=0 && Overlap[1]!=0)
    {
        answer.push_back(Overlap[0]);
        answer.push_back(Overlap[1]);
        return answer;
    }
    else if (Last[1] < Overlap[1] && Last[1] != 0 && Overlap[1] != 0)
    {
        answer.push_back(Last[0]);
        answer.push_back(Last[1]);
        return answer;
    }
    else if (Last[1]==Overlap[1])
    {
        answer.push_back(Last[0]);
        answer.push_back(Last[1]);
        return answer;
    }

    else
    {
        if (Last[1] == 0)
        {
            answer.push_back(Overlap[0]);
            answer.push_back(Overlap[1]);
            return answer;
        }
        else if (Overlap[1] == 0)
        {
            answer.push_back(Last[0]);
            answer.push_back(Last[1]);
            return answer;
        }
    }

    if (!OneWordCheck)
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main()
{
    vector<string> a = { "hello", "one", "even", "never", "now", "world", "draw" };
    vector<int> v = solution(3, a);

    for (auto i : v)
        cout << i;
    return 0;
}