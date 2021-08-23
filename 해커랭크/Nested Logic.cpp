#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int D1, M1, Y1;
    int D2, M2, Y2;
    cin >> D1 >> M1 >> Y1;
    cin >> D2 >> M2 >> Y2;
    int Dcost = 0;
    int Mcost = 0;
    if (Y1 == Y2)
    {
        if (M1 == M2)
        {
            Dcost = (D1 - D2)*15;
        }
        else if(M1>M2)
        {
            //if (D1 - D2 < 0)
                Mcost = (M1 - M2) * 500;
           // else if(D1-D2>0)
            //{
           //     Mcost = (M1 - M2) * 500;
           //     Dcost = (D1 - D2) * 15;
           // }
        }
    }
    else if (Y1>Y2)
    {
        cout << 10000;
        return 0;
    }
    cout << Dcost + Mcost;
    return 0;
}
