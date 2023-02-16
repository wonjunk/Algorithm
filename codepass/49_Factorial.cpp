/// 1부터 어떤 양의 정수 n까지의 정수를 모두 곱한 것을 말하며 n!로 나타낸다
/// 0! = 1, 1! =1, 2! = 2 x 1 = 2 .... n! = n * (n-1)!
/// 
/// * 결과가 int범위를 넘는 경우 
/// 자료형 long long 사용
/// 입력 / 출력 서식문자 % lld 사용
/// 
/// input : n   ----- 입력은 한 줄로 이뤄지며 팩토리얼의 숫자 n(1≤n≤15)이 입력된다.
/// output : n! ----- n!에 대한 계산 결과를 "출력예"처럼 과정을 출력하고 마지막에 결과를 출력한다.

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
		cout << "0! = " << result << "\n"; // 0!의 경우 1로 정의
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