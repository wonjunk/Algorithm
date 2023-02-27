#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n;
	char ch = 'A';

	char arr[100][100];

	cin >> n;

	for (int j = 0; j < n; j++)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < n; i++)
			{
				arr[i][j] = ch++;
				if (ch - 1 == 'Z')
				{
					ch = 'A';
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= -0; i--)
			{
				arr[i][j] = ch++;
				if (ch - 1 == 'Z')
				{
					ch = 'A';
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}