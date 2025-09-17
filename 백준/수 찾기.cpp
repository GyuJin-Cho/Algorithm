#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> Arr;
int N,M;

void BinarySearch(const int& _Search)
{
    int start = 0;
    int end = N-1;
    int mid = 0;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(Arr[mid]==_Search)
        {
            cout<<1<<'\n';
            return;
        }
        else if(Arr[mid] > _Search)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    cout<<0<<'\n';
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>N;
    Arr.resize(N);
    for(int i=0;i<N;i++)
    {
        cin>>Arr[i];
    }
    cin>>M;
    int serach;
    sort(Arr.begin(),Arr.end());
    for(int i=0;i<M;i++)
    {
        cin>>serach;
        BinarySearch(serach);
    }
    return 0;
}