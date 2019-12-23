#include<iostream>
#include<math.h>
using namespace std;

int a[101][3];
int n, dis;
int r(int x, int y, int rx, int ry) {
	return sqrt((x - rx) * (x - rx) + (y - ry) * (y - ry));
}

bool dfs(int x, int y) {
	if (50 - abs(x) <= dis || 50 - abs(y) <= dis) {
		//cout << "Yes" << endl;
		return true;
	}
	for (int i = 0; i < n; i++)
		if (a[i][2] == 0)
			if (r(a[i][0], a[i][1], x, y) <= dis) {
				a[i][2] = 1;
				if (dfs(a[i][0], a[i][1])) {
					//a[i][2] = 0;
					return true;
				}
			}
	return false;
}
bool FirstJump(int x, int y) {
	if (50 - abs(x) <= dis + 7.5 || 50 - abs(y) <= dis + 7.5) {
		//cout << "Yes" << endl;
		return true;
	}
	for (int i = 0; i < n; i++)
		if (a[i][2] == 0)
			if (r(a[i][0], a[i][1], x, y) <= dis + 7.5) {
				a[i][2] = 1;
				if (dfs(a[i][0], a[i][1])) {
					//a[i][2] = 0;
					return true;
				}
			}
	return false;
}
int main() {
	cin >> n >> dis;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i][0] = x;
		a[i][1] = y;
		a[i][2] = 0;
	}
	if (FirstJump(0, 0)) cout << "Yes" << endl;
	else cout << "No" << endl;
	system("pause");
}
