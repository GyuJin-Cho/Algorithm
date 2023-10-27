#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;
const int NUMBERMAX = 10;

const int steps[NUMBERMAX][NUMBERMAX] =
{
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

int dp[MAX][NUMBERMAX][NUMBERMAX];

string CopyNumbers;

int Solve(int idx, int left, int right)
{
    if (idx == CopyNumbers.length())
        return 0;

    int& result = dp[idx][left][right];

    if (result != -1)
        return result;

    int cur = CopyNumbers[idx] - 48;
    if(left==cur||right==cur)
    {
        return result = 1 + Solve(idx + 1, left, right);
    }

    return result = min(Solve(idx + 1, cur, right) + steps[left][cur], 
        Solve(idx + 1, left, cur) + steps[right][cur]);

}



int solution(string numbers)
{
    int answer = 0;

    memset(dp, -1, sizeof(dp));
    CopyNumbers = numbers;

    return Solve(0,4,6);
}

int main()
{
    cout << solution("1756");

    return 0;
}