#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array)
{
    int answer = 0;

    sort(array.begin(), array.end());

    int index = array.size() / 2;

    answer = array[index];

    return answer;
}

int main()
{
    vector<int> v = {9,-1,0};

    cout << solution(v);

	return 0;
}