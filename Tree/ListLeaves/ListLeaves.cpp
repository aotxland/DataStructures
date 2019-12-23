#include<iostream>
#include<queue> 

using namespace std;
constexpr auto MaxTree = 10;
#define ElementType char
#define Tree int
constexpr auto Null = -1;
struct TreeNode
{
	ElementType Data;
	Tree Left;
	Tree Right;
} TR[MaxTree];

Tree BuildTree(struct TreeNode T[]);
void ListLeave(Tree root);

int main() {
	Tree T=BuildTree(TR);
	ListLeave(T);
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
		char a, b;
		cin >> a >> b;
		if (a == '-') {
			T[i].Data = i;
			T[i].Left = Null;
		}
		else {
			T[i].Data = i;
			T[i].Left = a - '0';
			check[T[i].Left] = 1;
		}
		if (b == '-') {
			T[i].Data = i;
			T[i].Right = Null;
		}
		else {
			T[i].Data = i;
			T[i].Right = b - '0';
			check[T[i].Right] = 1;
		}
	}
	Tree root = -1;
	for (int i = 0; i < n; i++) {
		if (check[i] == 0)
			root = i;
	}
	return root;
}

void ListLeave(Tree root)
{
	queue <int> List;
	queue <int> Out;
	List.push(root);
	while (!List.empty()) {
		int l = List.front();
		if (TR[l].Left == Null && TR[l].Right == Null) {
			//cout << l << ' ';
			Out.push(l);
		}
		List.pop();
		if (TR[l].Left != Null)
			List.push(TR[l].Left);
		if (TR[l].Right != Null)
		List.push(TR[l].Right);
		
	}
	int n = Out.size();
	if (n != 1) {
		for (int i = 0; i < n - 1; i++) {
			cout << Out.front() << " ";
			Out.pop();
		}
	}
	cout << Out.front();
}
