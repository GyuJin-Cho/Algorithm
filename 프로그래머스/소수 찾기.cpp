#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
constexpr long long MAX = 10000000;
bool check[MAX];

void IsPrime()
{
    memset(check, true, sizeof(check));
    check[0] = false;
    check[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        if (check[i])
        {
            for (int j = i * 2; j < MAX; j+=i)
            {
                check[j] = false;
            }
        }
    }
}

int solution(string numbers)
{
    int answer = 0;
    IsPrime();
    sort(numbers.begin(), numbers.end());
    set<int> s;
    do
    {
        string tmp = "";
        for (int i = 0; i < numbers.size(); i++)
        {
            tmp += numbers[i];
            s.insert(stoi(tmp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (const auto& i : s)
    {
        if (check[i])
            answer++;
    }

    return answer;
}

int main()
{
    cout << solution("17");

    return 0;
}