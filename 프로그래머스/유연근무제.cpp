#include <iostream>
#include <vector>
using namespace std;

int toMinutes(int time)
{
    int h = time / 100;
    int m = time % 100;
    return h * 60 + m;
}

int toHHMM(int minutes)
{
    int h = minutes / 60;
    int m = minutes % 60;
    return h * 100 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
    int n = schedules.size();
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        int schedLimit = toMinutes(schedules[i]) + 10;
        bool ok = true;

        for (int j = 0; j < 7; j++)
        {
            int day = (startday + j - 1) % 7 + 1;
            if (day == 6 || day == 7)
                continue;

            int arrive = toMinutes(timelogs[i][j]);
            if (arrive > schedLimit)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            answer++;
    }
    return answer;
}

int main() {
    vector<int> schedules1 = {700, 800, 1100};
    vector<vector<int>> timelogs1 =
    {
        {710, 2359, 1050, 700, 650, 631, 659},
        {800, 801, 805, 800, 759, 810, 809},
        {1105, 1001, 1002, 600, 1059, 1001, 1100}
    };
    cout << solution(schedules1, timelogs1, 5) << endl;

    vector<int> schedules2 = {730, 855, 700, 720};
    vector<vector<int>> timelogs2 =
    {
        {710, 700, 650, 735, 700, 931, 912},
        {908, 901, 805, 815, 800, 831, 835},
        {705, 701, 702, 705, 710, 710, 711},
        {707, 731, 859, 913, 934, 931, 905}
    };
    cout << solution(schedules2, timelogs2, 1) << endl;

    return 0;
}
