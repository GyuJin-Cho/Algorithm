#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n)
{
    int A, B, C;
    A = box[0] / n;
    B = box[1] / n;
    C = box[2] / n;

    return A*B*C;
}

int main()
{
    vector<int> box = { 10,8,6 };
    cout << solution(box, 3);

    return 0;
}