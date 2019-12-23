#include<iostream>
#include<vector>
#include "MyStack.h"

using namespace std;
bool judge(int m,int n, int list[]);
int main() {
	int member, num, n;
	cin >> member >> num >> n;
	for (int i = 1; i < n + 1; i++) {
		int list[1002];
		for (int j = 1; j < num + 1; j++) {
			cin >> list[j];
		}
		if (judge(member, num, list)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system("pause");
	return 0;
}

bool judge(int m, int n, int list[])
{
	MyStack<int> astack(m);
	int count = 1;
	for (int i = 1; i < n + 1; i++) {
		if (list[count] > i) {
			if (astack.stackFull()) return false;
			astack.push(i);
		}
		else 
			while (list[count] <= i) {
				if (list[count] == i) {
					if (astack.stackFull()) return false;
					count++;
					if (count == n + 1)return true;
				}
				else {
					if (astack.stackEmpty()) return false;
					int t;
					astack.pop(t);
					if (list[count] == t) {
						if (astack.stackFull()) return false;
						count++;
						if (count == n + 1)return true;
					}
					else return false;
			}
		}
	}

	return true;
}
