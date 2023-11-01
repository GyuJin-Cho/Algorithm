#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool col[13], diag1[26], diag2[26];
int answer = 0;
void nQueen(int row ,int& N)
{
    if (row == N) 
    {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) 
    {
        if (!col[i] && !diag1[row + i] && !diag2[row - i + N - 1]) 
        {
            col[i] = diag1[row + i] = diag2[row - i + N - 1] = true;
            nQueen(row + 1,N);
            col[i] = diag1[row + i] = diag2[row - i + N - 1] = false;
        }
    }
}

int solution(int n)
{
    nQueen(0, n);
    return answer;
}

int main()
{
    cout << solution(4);

    return 0;
}