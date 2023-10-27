#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer;
    int yx[4] = { 51,51,0,0 };

    for(int i=0;i<wallpaper.size();i++)
    {
        for(int j = 0; j < wallpaper[i].length();j++)
        {
	        if(wallpaper[i][j] == '#')
	        {
                yx[0] = min(yx[0], i);
                yx[1] = min(yx[1] , j);
                yx[2] = max(yx[2], i + 1);
                yx[3] = max(yx[3], j + 1);
	        }
        }
    }
    for (int i = 0; i < 4; i++)
        answer.push_back(yx[i]);
    return answer;
}

int main()
{
    vector<string> wall = { "..........", ".....#....", "......##..", "...##.....", "....#....." };
    vector<int> ans = solution(wall);

    for (auto i : ans)
        cout << i << ' ';

    return 0;
}