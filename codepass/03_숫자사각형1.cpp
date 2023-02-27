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
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = num++;
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