#include<iostream>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
using namespace std;

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
} T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
bool Isomorphic(Tree R1,Tree R2);

int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) printf("Yes\n");
	else printf("No\n");
	system("pause");
	return 0;
}

Tree BuildTree(struct TreeNode T[])
{
	int n,check[MaxTree];
	cin >> n;
	for (int i = 0; i < n; i++)
		check[i] = 0;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		T[i].Element = a;
		if (b == '-') {
			T[i].Left = Null;
		}
		else {
			T[i].Left = b - '0';
			check[T[i].Left] = 1;
		}
		if (c == '-') {
			T[i].Right = Null;
		}
		else {
			T[i].Right = c - '0';
			check[T[i].Right] = 1;
		}
	}
	if (n == 0) {
		T[0].Element = 'A';
		T[0].Left = Null;
		T[0].Right = Null;
	}
	for (int i = 0; i < n; i++)
		if (check[i] == 0)
			return i;
}

bool Isomorphic(Tree R1, Tree R2)
{
	int num = 0;
	if (T1[R1].Left != Null) num++;
	if (T1[R1].Right != Null) num++;
	if (T2[R2].Left != Null) num++;
	if (T2[R2].Right != Null) num++;
	if (num == 1 || num == 3)
		return false;
	if (num = 0)
		return true;
	if (T1[R1].Element != T2[R2].Element) {
		return false;
	}
	if (T1[R1].Left != Null && T1[R1].Right == Null) {
		if (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element && T2[R2].Right == Null)
			if (!Isomorphic(T1[R1].Left, T2[R2].Left))
				return false;
		if (T1[T1[R1].Left].Element == T2[T2[R2].Right].Element && T2[R2].Left == Null) {
			int temp;
			temp = T2[R2].Left;
			T2[R2].Left = T2[R2].Right;
			T2[R2].Right = temp;
			if (!Isomorphic(T1[R1].Left, T2[R2].Left))
				return false;
		}
	}
	if (T1[R1].Left == Null && T1[R1].Right != Null) {
		if (T1[T1[R1].Right].Element == T2[T2[R2].Right].Element && T2[R2].Left == Null)
			if (!Isomorphic(T1[R1].Right, T2[R2].Right))
				return false;
		if (T1[T1[R1].Right].Element == T2[T2[R2].Left].Element && T2[R2].Right == Null) {
			int temp;
			temp = T2[R2].Left;
			T2[R2].Left = T2[R2].Right;
			T2[R2].Right = temp;
			if (!Isomorphic(T1[R1].Right, T2[R2].Right))
				return false;
		}
	}
	if (T1[R1].Left != Null && T1[R1].Right != Null) {
		if (T1[T1[R1].Left].Element == T2[T2[R2].Right].Element || T1[T1[R1].Right].Element == T2[T2[R2].Left].Element) {
			int temp;
			temp = T2[R2].Left;
			T2[R2].Left = T2[R2].Right;
			T2[R2].Right = temp;
			if (!Isomorphic(T1[R1].Left, T2[R2].Left) || !Isomorphic(T1[R1].Right, T2[R2].Right))
				return false;
		}
		if (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element || T1[T1[R1].Right].Element == T2[T2[R2].Right].Element) {
			if (!Isomorphic(T1[R1].Left, T2[R2].Left) || !Isomorphic(T1[R1].Right, T2[R2].Right))
				return false;
		}
	}
	return true;
}
