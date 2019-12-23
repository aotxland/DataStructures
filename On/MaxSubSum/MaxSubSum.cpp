#include<iostream>
#include<vector>

using namespace std;

vector<int> Online(vector<int> A, int N)
{
	int ThisSum[3], MaxSum[3];
	int i;
	ThisSum[0] = MaxSum[0] = 0;
	ThisSum[1] = 0;
	ThisSum[2] = 0;
	bool flag = false;
	for (i = 0; i < N; i++) {
		ThisSum[0] += A[i]; /* �����ۼ� */
		if (ThisSum[0] > MaxSum[0]) {
			MaxSum[0] = ThisSum[0]; /* ���ָ��������µ�ǰ��� */
			MaxSum[1] = ThisSum[1];
			ThisSum[2] = i;
			MaxSum[2] = ThisSum[2];
		}
		else if (ThisSum[0] < 0) {/* �����ǰ���к�Ϊ�� */
			ThisSum[0] = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
			ThisSum[1] = i + 1;
			ThisSum[2] = 0;
		}
		if (A[i] >= 0) {   //���ǲ��Ƕ��Ǹ���
			flag = true;
		}

	}
	if (MaxSum[0] == 0 && flag) {
		MaxSum[1] = 0;
		MaxSum[2] = 0;
		A[0] = 0;
	}
	if (MaxSum[0] == 0 && !flag) {
		MaxSum[1] = 0;
		MaxSum[2] = N - 1;
	}
	vector<int> out;
	out.push_back(MaxSum[0]);
	out.push_back(A[MaxSum[1]]);
	out.push_back(A[MaxSum[2]]);
	return out;
}

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	vector<int> out = Online(a, n);
	cout << out[0] << ' ' << out[1] << ' ' << out[2] << endl;
	system("pause");
	return 0;
}