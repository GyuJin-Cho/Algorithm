#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights)
{
    long long answer = 0;
    vector<long long> cnt(1001, 0);
    for (int i = 0; i < weights.size(); i++)
        cnt[weights[i]]++;

    for(int i=0;i<weights.size();i++)
    {
	    if(weights[i]%2==0)
	    {
            long long l = (weights[i]/2) * 3;
            if (l <= 1000)
                answer += cnt[l];
	    }
        if(weights[i]%3==0)
        {
            long long l = (weights[i] / 3) * 4;
            if (l <= 1000)
                answer += cnt[l];
        }

        long long l = weights[i] * 2;
        if (l <= 1000)
            answer += cnt[l];
    }

    for(int i=100;i<=1000;i++)
    {
	    if(cnt[i]>=2)
	    {
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2;
	    }
    }

    return answer;
}

int main()
{
    vector<int> w = { 100,180,360,100,270 };
    cout << solution(w);

    return 0;
}