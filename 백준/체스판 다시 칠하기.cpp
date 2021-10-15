#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};
string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};
string Board[50];
int WB_Count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i + x][j + y] != WB[i][j])
                count++;
        }
    }
    return count;
}

int BW_Count(int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i + x][j + y] != BW[i][j])
                count++;
        }
    }
    return count;
}

int main()
{
    int Min = 111111111;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; i++)
    {
        cin >> Board[i];
    }

    for (int i = 0; i + 8 <= x; i++)
    {
        for (int j = 0; j + 8 <= y; j++)
        {
            int tmp;
            tmp = min(WB_Count(i, j), BW_Count(i, j));
            if (tmp < Min)
                Min = tmp;
        }
    }
    cout << Min;
    return 0;
}