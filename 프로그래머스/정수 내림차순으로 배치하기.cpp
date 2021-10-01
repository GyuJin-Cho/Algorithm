#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

long long solution(long long n)
{
    long long answer = 0;

    string s = to_string(n);
    vector<long long> a;
    for(int i=0;i<s.length();i++)
    {
        a.push_back(s[i] - '0');
    }
    sort(a.begin(), a.end(), cmp);
    s = "";
    for(int i=0;i<a.size();i++)
    {
        s += to_string(a[i]);
    }
    answer = stoll(s);
    return answer;
}

int main()
{
    cout << solution(8000000000);
    return 0;
}