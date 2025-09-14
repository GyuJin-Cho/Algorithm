#include<iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    unsigned long long s;
    cin>>s;

    unsigned long long num = 1;
    unsigned long long sum = 0;
    unsigned long long cnt = 0;

    while(1)
    {
        sum += num;
        cnt++;
        if(sum > s)
        {
            cnt--;
            break;
        }
        num++;
    }
    cout<<cnt;
}