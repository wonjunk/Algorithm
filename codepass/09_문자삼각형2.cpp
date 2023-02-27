#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n;
	char ch = 'A';

	char arr[100][100] = { };

	cin >> n;
	if (n % 2 == 0 || n > 100 || n < 1)
	{
		cout << "INPUT ERROR\n";
		return 0;
	}

	for (int j = n / 2; j >= 0; j--)
	{
		for (int i = -(n / 2 - j); i <= (n / 2 - j); i++)
		{
			arr[i + (n / 2)][j] = ch++;
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