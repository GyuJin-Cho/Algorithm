#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;
tuple<string, int, int, int> t[101];

bool cmd(tuple<string, int, int, int> t1, tuple<string, int, int, int> t2)
{
    if (get<3>(t1) == get<3>(t2))
    {
        if (get<2>(t1) == get<2>(t2))
        {
            return get<1>(t1) > get<1>(t2);
        }
        else
        {
            return get<2>(t1) > get<2>(t2);
        }
    }
    else
    {
        return get<3>(t1) > get<3>(t2);
    }
}

int main()
{
    int N;
    cin >> N;
	string name;
    int day, month, year;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> day >> month >> year;
        t[i] = make_tuple(name, day, month, year);
    }

    sort(t, t + N, cmd);
    cout << get<0>(t[0]) << '\n' << get<0>(t[N - 1]);

}
