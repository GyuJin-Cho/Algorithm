#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) 
{
    int answer = -11111;

    vector<int> v;
    for (int i = 0; i < dungeons.size(); i++)
    {
        v.push_back(i);
    }

    do
    {
        int CountK = k;
        int cnt = 0;

        for (int i = 0; i < v.size(); i++)
        {
            int minHealth = dungeons[v[i]][0];
            int useHealth = dungeons[v[i]][1];

            if (minHealth > CountK)
            {
                continue;
            }

            CountK -= useHealth;
            cnt++;
        }
        
        answer = max(answer, cnt);

    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main()
{
    vector<vector<int>> v = { {80,20},{50,40},{30,10} };
    cout << solution(80, v);

    return 0;
}