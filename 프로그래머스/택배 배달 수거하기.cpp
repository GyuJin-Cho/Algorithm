#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;

    int d = 0;
    int p = 0;
    int cnt = 0;

    for(int i=n-1;i>=0;i--)
    {
        d -= deliveries[i];
        p -= pickups[i];

        while(1)
        {
            if (d >= 0 && p >= 0)
                break;
            d += cap;
            p += cap;
            cnt++;
        }
        answer += (i + 1) * 2 * cnt;
        cnt = 0;
    }

    return answer;
}

int main()
{

    vector<int> d={ 1, 0, 2, 0, 1, 0, 2 };
    vector<int> p={ 0, 2, 0, 1, 0, 2, 0 };

    cout << solution(2, 7, d, p);

    return 0;
}