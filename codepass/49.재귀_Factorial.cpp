/// 1���� � ���� ���� n������ ������ ��� ���� ���� ���ϸ� n!�� ��Ÿ����
/// 0! = 1, 1! =1, 2! = 2 x 1 = 2 .... n! = n * (n-1)!
/// 
/// * ����� int������ �Ѵ� ��� 
/// �ڷ��� long long ���
/// �Է� / ��� ���Ĺ��� % lld ���
/// 
/// input : n   ----- �Է��� �� �ٷ� �̷����� ���丮���� ���� n(1��n��15)�� �Էµȴ�.
/// output : n! ----- n!�� ���� ��� ����� "��¿�"ó�� ������ ����ϰ� �������� ����� ����Ѵ�.

#include <iostream>

using namespace std;

long long int Factorial(int n);

int main(void) {

	int n;
	cin >> n;

	long long int result = 0;
	result = Factorial(n);

	cout << result << "\n";

	return 0;
}

long long int Factorial(int n) {
	long long int result = 0;

	if (n == 0) {
		result = 1;
		cout << "0! = " << result << "\n"; // 0!�� ��� 1�� ����
	} else if (n == 1) {
		result = 1;
		cout << "1! = " << result << "\n";
	}
	else {
		cout << n << "! = " << n << " * " << n - 1 << "!" << "\n";
		result = n * Factorial(n - 1);
	}

	return result;
}