#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money)
{
    vector<int> answer;

    int price = 5500;
    int result = 0;
    int changemoney = 0;

    result = money / price;
    changemoney = money - (price * result);

    answer.push_back(result);
    answer.push_back(changemoney);

    return answer;
}

int main()
{
    vector<int> a = solution(15000);
    for (auto i : a)
        cout << i << " ";
    return 0;
}