#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<int> numbers, vector<int> our_score, vector<int> score_list) {
    int num_student = numbers.size();
    vector<string> answer(num_student);

    for (int i = 0; i < num_student; i++) {
        if (our_score[i] == score_list[numbers[i] - 1]) {
            answer[i] = "Same";
        }
        else {
            answer[i] = "Different";
        }
    }

    return answer;
}

int main()
{
    vector<string> ans = solution({ 1 }, { 100 }, { 100,80,90,84,20 });
    for (string i : ans)
        cout << i << ' ';

    return 0;
}