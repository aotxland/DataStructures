#include<iostream>
using namespace std;
#define MaxSize 10000
typedef int UnionType[MaxSize];
void Check(int, int, UnionType);
void Connect(int, int, UnionType);
void CheckNetwork(UnionType,int);
int Find(UnionType S, int X)
{
	if (S[X] < 0) /* 找到集合的根*/
		return X;
	else
		return S[X] = Find(S, S[X]);
}
void Union(UnionType S, int Root1, int Root2)
{
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}
int main() {
	int n;
	cin >> n;
	char c;
	cin >> c;
	UnionType U;
	for (int i = 0; i < n + 1; i++) U[i] = -1;
	while (c!='S') {
		int a, b;
		cin >> a >> b;
		if (c == 'C') Check(a, b, U);
		if (c == 'I') Connect(a, b, U);
		cin >> c;
	} 
	CheckNetwork(U, n);
	system("pause");
}

void Connect(int u, int v, UnionType S)
{
	int Root1, Root2;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2)
		Union(S, Root1, Root2);
}

void Check(int u, int v, UnionType S)
{
	int Root1, Root2;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2)
		printf("yes\n");
	else printf("no\n");
}

void CheckNetwork(UnionType S, int n)
{
	int i, counter = 0;
	for (i = 0; i < n; i++) {
		if (S[i] < 0) counter++;
	}
	if (counter == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", counter);
}
