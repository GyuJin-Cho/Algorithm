#include <iostream>
using namespace std;

int main()
{
	int a, b, c, product;
	int quotient, remainder;
	int count[10] = { 0 }; // �ε����� �ش� �����̰� �׿� �ش��ϴ� ���� ���� Ƚ��

	cin >> a >> b >> c;
	product = a * b * c;

	do {
		quotient = product / 10;  // ���� ���
		remainder = product % 10; // ������ ���
		product = quotient;       // ���� �ٽ� ������ ����

		count[remainder]++;       // �������� �ش��ϴ� ���̹Ƿ� �ش� �ε��� 1 ����

	} while (quotient != 0);     // ���� 0�� �Ǳ� ������ �ݺ�

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}