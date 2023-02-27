#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n, m;
	int num = 1;

	int arr[100][100];

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				arr[i][j] = num++;
			}
		}
		else
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = num++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}