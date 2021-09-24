#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

using namespace std;
int GCD(int a, int b)
{         
    if (a == 0) 
        return b;
    return GCD(b % a, a);
}
int LCM(int a, int b)
{         
    return a * b / GCD(a, b);
}
int solution(vector<int> arr)
{
    int answer = 0;
    answer = arr[0];
    for (int i = 1; i < arr.size(); i++) 
    {
        answer = LCM(answer, arr[i]);
    }
    return answer;
}

int main()
{
    vector<int> arr = { 2,6,8,14 };
    cout << solution(arr);
    return 0;
}