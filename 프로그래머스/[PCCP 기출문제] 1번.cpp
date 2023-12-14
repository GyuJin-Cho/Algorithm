#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks)
{
    int fulltime = bandage[0];
    int healpersecond = bandage[1];
    int fullhealbonus = bandage[2];
    int nowhealth = health;

    int last = 0;
    for (int i = 0; i < attacks.size(); i++)
    {
        int attacktime = attacks[i][0];
        int damage = attacks[i][1];
        int range = attacktime - last - 1;
        last = attacktime;

        while (range >= fulltime)
        {
            nowhealth += fulltime * healpersecond;
            nowhealth += fullhealbonus;
            range -= fulltime;
        }
        nowhealth += range * healpersecond;
        if (nowhealth > health) nowhealth = health;

        nowhealth -= damage;
        if (nowhealth <= 0)
            return -1;
    }
    return nowhealth;
}

int main()
{
    cout << solution({ 5, 1, 5 }, 30, { {2,10},{9,15},{10,5},{11,5} });

    return 0;
}