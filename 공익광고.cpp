#include<iostream>
#include <string>
#include <vector>

using namespace std;

long Total[360000] = { 0, };

long stringToSec(string str)
{
    long sec = 0;

    string strHour = str.substr(0, 2); //subtract str
    string strMin  = str.substr(3, 2);
    string strSec  = str.substr(6, 2);

    sec = stoi(strHour) * 3600; // atoi,itoa,atof,itof
    sec = sec + stoi(strMin) * 60;
    sec = sec + stoi(strSec);
    return sec;
}

string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";

    // log 시간을 Total에 담는다

    for (int i = 0; i < logs.size(); i++)
    {
        int start = stringToSec(logs[i].substr(0,8));
        int end = stringToSec(logs[i].substr(9,8));

        for (int j = start; j < end; j++)
        {
            Total[j]++;
        }
    }

    long nPlayTime = stringToSec(play_time);
    long nAdvTime = stringToSec(adv_time);

    long sum, max, index;
    sum = max = index = 0;
    for (int i = 0; i < nAdvTime; i++)
    {
        sum = sum + Total[i];
    }
    max = sum;

    for (int i = nAdvTime; i < nPlayTime; i++)
    {
        sum = sum + Total[i];
        sum = sum - Total[i - nAdvTime];
        if (sum > max)
        {
            max = sum;
            index = i - nAdvTime + 1;
        }
    }

    long sec = index % 60;
    index = index / 60;
    long min = index % 60;
    index = index / 60;
    long hour = index;
    if (hour >= 10)
    {
        answer += to_string(hour);
        answer += ":";
    }
    else
    {
        answer += "0";
        answer += to_string(hour);
        answer += ":";
    }
    if (min >= 10)
    {
        answer += to_string(min);
        answer += ":";
    }
    else
    {
        answer += "0";
        answer += to_string(min);
        answer += ":";
    }
    if (sec >= 10)
    {
        answer += to_string(sec);
       
    }
    else
    {
        answer += "0";
        answer += to_string(sec);
       
    }
   // answer += to_string(hour);
   // answer += ":";
   // answer += to_string(min);
   // answer += ":";
   // answer += to_string(sec);

   //char buf[200];
   //sprintf_s(buf, "%02d:%02d:%02d", hour, min, sec);
   //
   //answer = buf;

    return answer;
}
int main()
{
    string answer;
    string play_time = "99:59:59";
    string abv_time= "25:00:00";

    vector<string> logs = 
    { 
       "69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"
    };

    answer = solution(play_time, abv_time, logs);
    cout << answer;
    system("Pause");
	return 0;
}