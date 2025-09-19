#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> Dist(N - 1);
    for (int i = 0; i < N - 1; ++i)
        cin >> Dist[i];

    vector<long long> Price(N);
    for (int i = 0; i < N; ++i)
        cin >> Price[i];

    long long MinPrice = Price[0];
    long long total = MinPrice * Dist[0];

    for (int i = 1; i < N - 1; ++i)
    {
        if (Price[i] < MinPrice)
            MinPrice = Price[i];
        total += MinPrice * Dist[i];
    }

    cout << total << '\n';
    return 0;
}