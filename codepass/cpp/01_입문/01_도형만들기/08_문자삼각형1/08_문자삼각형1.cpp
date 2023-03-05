#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n;
	char ch = 'A';

	char arr[100][100] = { };

	cin >> n;

	for (int i = n - 1; i < n + (n - 1); i++)
	{
		for (int j = n - 1; j >= i - (n - 1); j--)
		{
			arr[i - j][j] = ch++;
			if (ch - 1 == 'Z')
			{
				ch = 'A';
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
			{
				cout << arr[i][j] << " ";
			}
			else
			{
				cout << " " << " ";
			}
		}
		cout << "\n";
	}
}