#include<iostream>

using namespace std;

int T;
string st;
int q = 4;
void Question(int n)
{
	cout << st << "\"����Լ��� ������?\"" << '\n';
	if (n == T)
	{
		cout << st <<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
		cout << st << "��� �亯�Ͽ���." << '\n';
		for (int i = 0; i < q; i++)
		{
			st.pop_back();
		}
		return;
	}
	else
	{
		cout << st << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
		cout << st << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
		cout << st << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';
		for (int i = 0; i < q; i++)
		{
			st += '_';
		}
		Question(n + 1);
	}
	cout << st << "��� �亯�Ͽ���." << '\n';
	if (!st.empty())
	{
		for (int i = 0; i < q; i++)
		{
			st.pop_back();
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."<<'\n';
	Question(0);
	return 0;
}