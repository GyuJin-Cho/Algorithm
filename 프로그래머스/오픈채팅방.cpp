#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> nick;
vector<string> UID;
vector<string> m;
int nickCount = 0;
int UIDCount = 0;
vector<string> solution(vector<string> record)
{
    vector<string> answer;
    string tmp;
    bool bnick=false, bm=false, bUID=false;
    for (int i = 0; i < record.size(); i++)
    {
        for (int j = 0; j < record[i].length(); j++)
        {
            if (record[i][j] == ' '&&!bm)
            {
                bm = true;
                m.push_back(tmp);
                tmp = "";
                continue;
            }
            else if (record[i][j] == ' ' && bm&&!bUID)
            {
                bUID = true;
                UID.push_back(tmp);
                tmp = "";
                continue;
            }
            else if (bUID&&bm)
            {
                bnick = true;
                tmp += record[i][j];
                continue;
            }
            tmp += record[i][j];
        }
        if (bnick)
        {
            nick.push_back(tmp);
        }
        bnick = false;
        bm = false;
        bUID = false;
        tmp = "";
    }

    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] == "Enter")
        {
            answer.push_back(nick[nickCount]);
            answer[i] += "님이 들어왔습니다.";
            int size = answer.size();
            for (int j = 0; j < size -2; j++)
            {
                if (UID[UIDCount] == UID[j])
                {
                    answer[j] = "";
                    answer[j] += nick[nickCount];
                    answer[j] += "님이 들어왔습니다.";
                }
            }
        }
        else if (m[i]=="Leave")
        {
            for (int j = 0; j < answer.size(); j++)
            {
                if (UID[UIDCount] == UID[j])
                {
                    answer.push_back(nick[nickCount]);
                    answer[UIDCount] += "님이 나갔습니다.";
                    nickCount--;
                    UIDCount--;
                    break;
                }
            }
        }
        else
        {
            for (int j = 0; j < answer.size()-1; j++)
            {
                if (UID[UIDCount] == UID[j])
                {
                    answer[j] = "";
                    answer[j] += nick[nickCount];
                    answer[j] += "님이 들어왔습니다.";
                }
            }
        }
        nickCount++;
        UIDCount++;
    }

    return answer;
}

int main()
{
    vector<string> answer = { "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan" };

    vector<string> s = solution(answer);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    return 0;
}