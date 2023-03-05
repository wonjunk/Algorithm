//����
// 
//�� û�ұⰡ �־����� ��, û���ϴ� ������ ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�κ� û�ұⰡ �ִ� ��Ҵ� N��M ũ���� ���簢������ ��Ÿ�� �� ������, 
// 1��1ũ���� ���簢�� ĭ���� �������� �ִ�.������ ĭ�� �� �Ǵ� �� ĭ�̴�.
// û�ұ�� �ٶ󺸴� ������ ������, �� ������ ��, ��, ��, ���� �ϳ��̴�.
// ������ �� ĭ��(r, c)�� ��Ÿ�� �� �ְ�, r�� �������κ��� ������ ĭ�� ����, c�� �������� ���� ������ ĭ�� �����̴�.
//
//�κ� û�ұ�� ������ ���� �۵��Ѵ�.
//
//1. ���� ��ġ�� û���Ѵ�.
//2. ���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�.
//	2-1. ���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
//	2-2. ���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
//	2-3. �� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
//	2-4.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
//
//�κ� û�ұ�� �̹� û�ҵǾ��ִ� ĭ�� �� û������ ������, ���� ����� �� ����.

//�Է�

//ù° �ٿ� ���� ũ�� N�� ���� ũ�� M�� �־�����. (3 �� N, M �� 50)
//
//��° �ٿ� �κ� û�ұⰡ �ִ� ĭ�� ��ǥ(r, c)�� �ٶ󺸴� ���� d�� �־�����.
// d�� 0�� ��쿡�� ������, 1�� ��쿡�� ������, 
// 2�� ��쿡�� ������, 3�� ��쿡�� ������ �ٶ󺸰� �ִ� ���̴�.
//
//��° �ٺ��� N���� �ٿ� ����� ���°� ���ʺ��� ���� �������, 
//�� ���� ���ʺ��� ���� ������� �־�����.�� ĭ�� 0, ���� 1�� �־�����.
// ������ ù ��, ������ ��, ù ��, ������ ���� �ִ� ��� ĭ�� ���̴�.
//
//�κ� û�ұⰡ �ִ� ĭ�� ���´� �׻� �� ĭ�̴�.

//���
//�κ� û�ұⰡ û���ϴ� ĭ�� ������ ����Ѵ�.

#include <iostream>

using namespace std;

void Cleaner_Working(int** Map, int* r, int* c, int* d, bool* flag, int* Count);
void Clear(int** Map, int r, int c, int* Count);
int Direction_Change(int d);

int main(void)
{
	int N, M;   // N : ���� ĭ ��, M : ���� ĭ ��
	int r, c, d; // r : x ��ǥ, c : y ��ǥ, d : ���� ����

	cin >> N >> M;
	cin >> r >> c >> d;

	// 2���� �迭 ���� �Ҵ�
	int** Map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[M];
	}

	// 2���� �迭 Map �����
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
		}
	}
	int Cleaning_Count = 0;

	bool Power_On = true;
	while (Power_On)
	{
		Cleaner_Working(Map, &r, &c, &d, &Power_On, &Cleaning_Count);
	}

	cout << Cleaning_Count << "\n";

	return 0;
}

void Cleaner_Working(int** Map, int* r, int* c, int* d, bool* flag, int* Count)
{
	int Direction_r[4] = { -1,0,1,0 }; // d - 0 :����, 1 : ����, 2 :����, 3 : ����
	int Direction_c[4] = { 0,1,0,-1 };

	Clear(Map, *r, *c, Count);

	int initial_direction = *d;
	while (true)
	{
		*d = Direction_Change(*d);
		if (Map[*r + Direction_r[*d]][*c + Direction_c[*d]] == 0)
		{
			*r += Direction_r[*d];
			*c += Direction_c[*d];
			break;
		}
		if (Direction_Change(*d + 1) == initial_direction)
		{
			if (Map[*r - Direction_r[*d]][*c - Direction_c[*d]] == 1)
			{
				*flag = false;
				break;
			}
			else
			{
				*r -= Direction_r[*d];
				*c -= Direction_c[*d];
			}
		}

	}
}

void Clear(int** Map, int r, int c, int* Count) {
	if (Map[r][c] == 0)
	{
		Map[r][c] = 2;
		*Count += 1;
	}
}

int Direction_Change(int d) {
	if (d == 0)
	{
		return 3;
	}
	else
	{
		return d - 1;
	}
}