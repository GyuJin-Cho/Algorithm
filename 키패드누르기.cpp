#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

vector<vector<int>> pad;
void Init()
{
    pad =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {0,-1,0}
    };
}

bool find(int left, int right,int Point,string hand)
{
    int PointX = 0;
    int PointY = 0;
    int mulLeft = 0;
    int mulRight = 0;
    bool check = false;
    for (int i = 0; i < pad.size(); i++)
    {
        for (int j = 0; j < pad[i].size(); j++)
        {
            if (pad[i][j] == left)
            {
                PointX = i;
                PointY = j;
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    check = false;
    for (int i = 0; i < pad.size(); i++)
    {
        for (int j = 0; j < pad[i].size(); j++)
        {
            if (pad[i][j] == Point)
            {
                mulLeft = abs((abs(abs(PointX) - abs(i))) + (abs(abs(PointY) - abs(j))));
                PointX = 0;
                PointY = 0;
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    check = false;
    for (int i = 0; i < pad.size(); i++)
    {
        for (int j = 0; j < pad[i].size(); j++)
        {
            if (pad[i][j] == right)
            {
                PointX = i;
                PointY = j;
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    check = false;
    for (int i = 0; i < pad.size(); i++)
    {
        for (int j = 0; j < pad[i].size(); j++)
        {
            if (pad[i][j] == Point)
            {
                mulRight = abs((abs(abs(PointX) - abs(i))) + (abs(abs(PointY) - abs(j))));
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    if (mulLeft < mulRight)
    {
        return true;
    }
    else if (mulLeft > mulRight)
    {
        return false;
    }
    else if (mulLeft == mulRight)
    {
        if (hand == "right")
            return false;
        else
            return true;
    }
}

string solution(vector<int> numbers, string hand) 
{
    string answer = "";
    map <string, int> m;
    m.insert(make_pair("left", 0));
    m.insert(make_pair("right", 0));
    Init();
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i]==1)
        {
            m["left"] = 1;
            answer += "L";
            continue;
        }
        if (numbers[i] == 4)
        {
            m["left"] = 4;
            answer += "L";
            continue;
        }
        if (numbers[i] == 7)
        {
            m["left"] = 7;
            answer += "L";
            continue;
        }
        if (numbers[i] == 3)
        {
            m["right"] = 3;
            answer += "R";
            continue;
        }
        if (numbers[i] == 6)
        {
            m["right"] = 6;
            answer += "R";
            continue;
        }
        if (numbers[i] == 9)
        {
            m["right"] = 9;
            answer += "R";
            continue;
        }
        if (numbers[i] == 2)
        {
            if (find(m["left"], m["right"], 2,hand))
            {
                m["left"] = 2;
                answer += "L";
            }
            else
            {
                m["right"] = 2;
                answer += "R";
            }
            continue;
        }
        if (numbers[i] == 5)
        {
            if (find(m["left"], m["right"], 5,hand))
            {
                m["left"] = 5;
                answer += "L";
            }
            else
            {
                m["right"] = 5;
                answer += "R";
            }
            continue;
        }
        if (numbers[i] == 8)
        {
            if (find(m["left"], m["right"], 8, hand))
            {
                m["left"] = 8;
                answer += "L";
            }
            else
            {
                m["right"] = 8;
                answer += "R";
            }
            continue;
        }
        if (numbers[i] == 0)
        {
            if (find(m["left"], m["right"], -1, hand))
            {
                m["left"] = -1;
                answer += "L";
            }
            else
            {
                m["right"] = -1;
                answer += "R";
            }
            continue;
        }
    }
    return answer;
}

int main()
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    string hand ="right";
    string a = solution(numbers, hand);
    cout << a;
    system("Pause");
    return 0;
}