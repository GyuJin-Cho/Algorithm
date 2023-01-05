#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[200];

int solution(vector<vector<int>> lines)
{
    int answer = 0;

    for (int i = 0; i < lines.size(); i++)
        for (int j = lines[i][0]; j < lines[i][1]; j++)
            arr[j + 100]++;

    for (int i = 0; i < 200; i++)
        if (arr[i] >= 2) answer++;

    return answer;
}

int main()
{
    vector<vector<int>> lines = { {0, 5},{3,9},{1,10} };
    cout << solution(lines);

    return 0;
}