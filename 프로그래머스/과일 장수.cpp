#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> temp;
int solution(int k, int m, vector<int> score)
{
    int answer = 0;
    temp = score;

    sort(temp.begin(), temp.end(), greater<int>());

    int size = temp.size() / m;
    int i = 0;
    while (size--)
    {
        answer += *min_element(temp.begin() + i, temp.begin() + i + m)*m;
        i += m;
    }


    return answer;
}

int main()
{
    vector<int> score = { 1, 2, 3, 1, 2, 3, 1 };
    cout << solution(3, 4, score);

    return 0;
}