#include<iostream>
#include <string>
#include <vector>

using namespace std;

int map[101][101];
int minChanged;

void rotate(int x1, int y1, int x2, int y2)
{
    int start = map[x1][y1];

    for (int i = x1; i < x2; i++) 
    {
        map[i][y1] = map[i + 1][y1];
        minChanged = min(minChanged, map[i][y1]);
    }

    for (int i = y1; i < y2; i++) 
    {
        map[x2][i] = map[x2][i + 1];
        minChanged = min(minChanged, map[x2][i]);
    }

    for (int i = x2; i > x1; i--) 
    {
        map[i][y2] = map[i - 1][y2];
        minChanged = min(minChanged, map[i][y2]);
    }

    for (int i = y2; i > y1 + 1; i--) 
    {
        map[x1][i] = map[x1][i - 1];
        minChanged = min(minChanged, map[x1][i]);
    }

    map[x1][y1 + 1] = start;
    minChanged = min(minChanged, map[x1][y1 + 1]);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;

    int size = queries.size();

    memset(map, 0, sizeof(map));

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            map[i][j] = (i - 1) * columns + j;
        }
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int x1, y1, x2, y2;

        x1 = queries[i][0];
        y1 = queries[i][1];
        x2 = queries[i][2];
        y2 = queries[i][3];

        minChanged = 111111;

        rotate(x1, y1, x2, y2);

        answer.push_back(minChanged);
    }

    return answer;
}

int main()
{
    vector<vector<int>> v = { {2,2,5,4},{3,3,6,6},{5,1,6,3} };

    vector<int> v1 = solution(6, 6, v);

    for (auto i : v1)
        cout << i;

    return 0;
}