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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> v;

    for (int i = 0; i < 14; i++) 
    {
        int inp; cin >> inp;
        v.push_back(inp);
    }

    int jun = 0, sung = 0;
    int _N = N;
    for (auto it : v)
    {   
        if (it <= _N)
        {
            jun = _N / it;
            _N = _N % it;
            break;
        }
    }
    jun = _N + (jun * v[13]); 

    int cnt = 0;
    int buy_idx = 1e9;
    for (int i = 1; i < v.size(); i++) 
    {
        if (v[i] < v[i - 1]) cnt++;
        else cnt = 0;
        if (cnt >= 3) 
        {   
            if (v[i] <= N)
            {  
                sung += N / v[i];    
                N = N % v[i];
                buy_idx = i;    
            }
        }
    }
    cnt = 0;
    bool flag = false;
    for (int i = buy_idx + 1; i < v.size(); i++) 
    {
        if (v[i] > v[i - 1]) cnt++;
        else cnt = 0;
        if (cnt >= 3)
        {   
            flag = true;   
            sung = sung * v[i];   
            break;
        }
    }

    if (!flag) 
        sung = N + (sung * v[13]); 

    if (sung > jun) 
        cout << "TIMING";
    else if (sung < jun)
        cout << "BNP";
    else 
        cout << "SAMESAME";
    return 0;
}