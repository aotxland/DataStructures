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
		ThisSum[0] += A[i]; /* 向右累加 */
		if (ThisSum[0] > MaxSum[0]) {
			MaxSum[0] = ThisSum[0]; /* 发现更大和则更新当前结果 */
			MaxSum[1] = ThisSum[1];
			ThisSum[2] = i;
			MaxSum[2] = ThisSum[2];
		}
		else if (ThisSum[0] < 0) {/* 如果当前子列和为负 */
			ThisSum[0] = 0; /* 则不可能使后面的部分和增大，抛弃之 */
			ThisSum[1] = i + 1;
			ThisSum[2] = 0;
		}
		if (A[i] >= 0) {   //看是不是都是负数
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