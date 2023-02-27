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
		else
		{
			cout << "INPUT ERROR!\n";
		}
	}

	for (int i = 1; i <= 9; i++)
	{
		if (s < e)
		{
			for (int j = s; j <= e; j++)
			{
				cout << j << " * " << i << " = " << setw(2) << j * i;
				cout << "   ";
			}
		}
		else
		{
			for (int j = s; j >= e; j--)
			{
				cout << j << " * " << i << " = " << setw(2) << j * i;
				cout << "   ";
			}
		}
		cout << "\n";
	}

	return 0;
}