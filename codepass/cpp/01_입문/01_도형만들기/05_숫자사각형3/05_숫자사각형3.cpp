#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int n;
	int num = 1;

	int arr[100][100];

	cin >> n;

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			arr[i][j] = num++;
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