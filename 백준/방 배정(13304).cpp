#include<iostream>
#include<map>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	int sex, grade;
	int junior = 0;
	int f[8]={0,};
	int m[8]={0,};
	while(n--)
	{
		cin >> sex >> grade;
		if(grade==1||grade==2)
		{
			junior++;
		}
		else if(sex==0)
		{
			if(grade==4 || grade == 6)
			{
				f[grade - 1]++;
			}
			else
			{
				f[grade]++;
			}
		}
		else
		{
			if (grade == 4 || grade == 6)
			{
				m[grade - 1]++;
			}
			else
			{
				m[grade]++;
			}
		}
	}

	int sum = 0;
	float div = float(junior) / float(k);
	sum += ceil(div);
	int fnum = 0;
	int mnum = 0;
	for(int i=3;i<=6;i++)
	{
		fnum += f[i];
		mnum += m[i];
		if(i==4)
		{
			div = float(fnum) / float(k);
			sum += ceil(div);
			div = float(mnum) / float(k);
			sum += ceil(div);
			fnum = 0;
			mnum = 0;
		}
		else if(i==6)
		{
			div = float(fnum) / float(k);
			sum += ceil(div);
			div = float(mnum) / float(k);
			sum += ceil(div);
		}
	}
	cout << sum;
	return 0;
}