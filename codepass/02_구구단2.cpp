#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int s, e;

	while (true)
	{
		cin >> s >> e;
		bool condition = (s > 1 && s < 10 && e >1 && e < 10);
		if (condition)
		{
			break;
		}
	}

	if (s < e)
	{
		for (int i = s; i <= e; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				cout << i << " * " << j << " = " << setw(2) << i * j;
				if (j % 3 == 0)
				{
					cout << "\n";
				}
				else
				{
					cout << "   ";
				}
			}
			cout << "\n\n\n";
		}
	}
	else
	{
		for (int i = s; i >= e; i--)
		{
			for (int j = 1; j <= 9; j++)
			{
				cout << i << " * " << j << " = " << setw(2) << i * j;
				if (j % 3 == 0)
				{
					cout << "\n";
				}
				else
				{
					cout << "   ";
				}
			}
			cout << "\n\n\n";
		}
	}

	return 0;
}