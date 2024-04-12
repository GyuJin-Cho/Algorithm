#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>
#include<tuple>

using namespace std;

int main() 
{
    int N, L;
    cin >> N >> L;
    vector<tuple<int, int, int>> shinho;
    for (int i = 0; i < N; i++) 
    {
        int d, r, g;
        cin >> d >> r >> g;
        shinho.push_back(make_tuple(d, r, g));
    }

    int CurrentTime = 0;
    int PreviousD = 0;

    for (int i = 0; i < N; i++) 
    {
        CurrentTime += get<0>(shinho[i]) - PreviousD;

        int cycle = get<1>(shinho[i]) + get<2>(shinho[i]);
        int TimeInCycle = CurrentTime % cycle;

        if (TimeInCycle < get<1>(shinho[i]))
        {
            CurrentTime += (get<1>(shinho[i]) - TimeInCycle);
        }

        PreviousD = get<0>(shinho[i]);
    }

    CurrentTime += L - PreviousD;

    cout << CurrentTime;

    return 0;
}