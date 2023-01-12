#include <string>
#include <vector>
#include <iostream>
using namespace std;

double solution(vector<int> numbers)
{
    double answer = 0;

    for (auto i : numbers)
        answer += i;

    return answer / numbers.size();
}

int main()
{
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << solution(numbers);

    return 0;
}