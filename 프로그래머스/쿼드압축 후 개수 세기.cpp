#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> map;

void DFS(int x, int y, int Size, vector<int>& answer)
{
    bool zero, one;
    zero = one = true;
    for (int i = x; i < x + Size; i++)
    {
        for (int j = y; j < y + Size; j++)
        {
            if (map[i][j] == 0)
                one = false;
            if (map[i][j] == 1)
                zero = false;
        }
    }

    if (zero == true)
    {
        answer[0]++;
        return;
    }
    if (one == true)
    {
        answer[1]++;
        return;
    }
    DFS(x, y, Size / 2, answer);
    DFS(x, y + Size / 2, Size / 2, answer);
    DFS(x + Size / 2, y, Size / 2, answer);
    DFS(x + Size / 2, y + Size / 2, Size / 2, answer);
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer(2,0);
    map = arr;
    DFS(0, 0, arr.size(), answer);

    return answer;
}

int main()
{
    vector<vector<int>> arr = { {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 1 },
        {0, 0, 0, 0, 1, 1, 1, 1},{0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 1, 1, 1, 1} };
    vector<int> a = solution(arr);
    for (auto i : a)
    {
        cout << i << " ";
    }
    return 0;
}