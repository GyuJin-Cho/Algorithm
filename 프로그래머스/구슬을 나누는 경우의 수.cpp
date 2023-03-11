#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//int Com(int n, int r)
//{
//    if (r == 0 || n == r)
//        return 1;
//    else
//        return Com(n - 1, r - 1) + Com(n - 1, r);
//}
int solution(int balls, int share)
{
    int answer = 0;

    vector<bool> v(balls, true);
    vector<int> arr;
    for(int i=1;i<=balls;i++)
    {
        arr.push_back(i);
    }
    for (int i = 0; i < balls-share; i++)
        v[i] = false;
    int cnt = 0;
    do
    {
        cnt++;
    } while (next_permutation(v.begin(), v.end()));

    //answer = Com(balls, share);
    answer = cnt;
    return answer;
}

int main()
{
    cout << solution(5, 3);

	return 0;
}