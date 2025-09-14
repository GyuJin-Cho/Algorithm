#include<iostream>

using namespace std;

int CharToIndex(char c)
{
    if(c=='A')
        return 0;
    if(c=='C')
        return 1;
    if(c=='G')
        return 2;
    return 3;
}

bool CheckVaild(int CountArr[], int Required[])
{
    for(int i = 0; i<4; i++)
    {
        if(CountArr[i] < Required[i])
            return false;
    }
    return true;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int S,P;
    cin>>S>>P;

    string dna;
    cin>>dna;

    int required[4];
    for(int i=0;i<4;i++)
        cin>>required[i];

    int CountArr[4] = {0};
    
    for(int i=0;i<P;i++)
    {
        CountArr[CharToIndex(dna[i])]++;
    }

    int ans = 0;
    if(CheckVaild(CountArr,required))
        ans++;

    for(int i=P; i<S; i++)
    {
        CountArr[CharToIndex(dna[i-P])]--;
        CountArr[CharToIndex(dna[i])]++;

        if(CheckVaild(CountArr,required))
            ans++;
    }    

    cout<<ans;
    return 0;
}