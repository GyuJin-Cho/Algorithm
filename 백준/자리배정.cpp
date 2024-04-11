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

    int C, R;
    cin >> C >> R;
    int H;
    cin >> H;

    int count = 0;

    int start[2] = { 1,0 };
    int swit = 1;
    if (C * R < H)
    {
        cout << "0" << endl;
        return 0;
    }
    else 
    {

        while (1)
        {
            
            for (int i = 0; i < R; i++)
            {
                start[1] += swit;
                count++;

                if (count == H) 
                {
                    cout << start[0] << " " << start[1] << endl;
                    return 0;
                }

            }

            C--;

            for (int i = 0; i < C; i++)
            {
                start[0] += swit;
                count++;
                if (count == H)
                {
                    cout << start[0] << " " << start[1] << endl;
                    return 0;
                }
            }

            R--;
            swit *= -1;

        }

    }

    return 0;
}