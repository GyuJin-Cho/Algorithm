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

using namespace std;
int N;
long long Min = 999999999999;
long long Max = -999999999999;
int main()
{
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector<int> Cal(4);
	for (int i = 0; i < 4; i++)
	{
		cin >> Cal[i];
	}
	vector<char> Calcul;
	char d[] = { '+','-','*','/' };
	for (int i = 0; i < Cal.size(); i++)
	{
		for (int j = 0; j < Cal[i]; j++)
		{
			Calcul.push_back(d[i]);
		}
	}

	sort(Calcul.begin(), Calcul.end());
	do
	{
		long long Calculator = 0;
		bool check = false;
		for (int i = 0; i < Calcul.size(); i++)
		{
			switch (Calcul[i])
			{
			case '+':
			{
				if (!check)
				{
					Calculator = A[i] + A[i + 1];
					check = true;
				}
				else
				{
					Calculator = Calculator + A[i + 1];
				}
				break;
			}
			case '-':
			{

				if (!check)
				{
					Calculator = A[i] - A[i + 1];
					check = true;
				}
				else
				{
					Calculator = Calculator - A[i + 1];
				}
				break;
			}
			case '*':
			{
				if (!check)
				{
					Calculator = A[i] * A[i + 1];
					check = true;
				}
				else
				{
					Calculator = Calculator * A[i + 1];
				}
				break;
			}
			case '/':
			{
				if (!check)
				{
					Calculator = A[i] / A[i + 1];
					check = true;
				}
				else
				{
					Calculator = Calculator / A[i + 1];
				}
				break;
			}
			}
		}
		Min = min(Min, Calculator);
		Max = max(Max, Calculator);

	} while (next_permutation(Calcul.begin(), Calcul.end()));
	cout << Max << '\n' << Min;
	return 0;
}