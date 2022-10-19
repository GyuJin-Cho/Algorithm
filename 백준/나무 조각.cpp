#include<iostream>

using namespace std;

int arr[6];
void Four();
void One();
void Four()
{
	if (arr[3] > arr[4])
	{
		int temp = arr[3];
		arr[3] = arr[4];
		arr[4] = temp;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	bool check = true;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] != i + 1)
		{
			check = false;
			break;
		}
	}
	if(!check)
	{
		
		One();
	}
}

void Three()
{
	if (arr[2] > arr[3])
	{
		int temp = arr[2];
		arr[2] = arr[3];
		arr[3] = temp;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	Four();
}

void Two()
{
	if (arr[1] > arr[2])
	{
		int temp = arr[1];
		arr[1] = arr[2];
		arr[2] = temp;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	Three();
}

void One()
{
	if (arr[0] > arr[1])
	{
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
	Two();
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	One();

	return 0;
}