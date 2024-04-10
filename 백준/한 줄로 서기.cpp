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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    vector<int> people(N); 
    vector<int> line(N); 

    for (int i = 0; i < N; i++) 
    {
        cin >> people[i];
    }

    for (int i = 0; i < N; i++) 
    {
        int space = people[i];
        for (int j = 0; j < N; j++) 
        {
            if (space == 0 && line[j] == 0) 
            {
                line[j] = i + 1;
                break;
            }
            else if (line[j] == 0) 
            {
                space--;
            }
        }
    }

    for (int i = 0; i < N; i++) 
    {
        cout << line[i] << " ";
    }

    return 0;
}