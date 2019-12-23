#include<iostream>
#include<stack>
#include<queue>

using namespace std;
constexpr auto MaxTree = 30;
#define ElementType int
#define Tree int
constexpr auto Null = -1;
queue <int> q;
struct TreeNode
{
	ElementType Data;
	Tree Left;
	Tree Right;
	Tree dad;
} TR[MaxTree];

Tree ReadTree(struct TreeNode T[]);
void postorder(Tree root);
void printqueue();

int main() {
	Tree T = ReadTree(TR);
	postorder(T);
	printqueue();
	system("pause");
}

Tree ReadTree(TreeNode T[])
{
	int n;
	cin >> n;
	T[0].dad = Null;
	int count = 0;
	bool isPop = false;
	int lastPush = 0;
	int lastPop = 0;
	stack<int> l;
	for (int i = 0; i < 2 * n; i++) {
		char c,cc;
		cin >> cc >> c;
		if (c == 'u') {
			cin >> cc >> cc;
			int ti;
			cin >> ti;
			l.push(count);
			T[count].Data = ti;
			T[count].Left = Null;
			T[count].Right = Null;
			if (isPop) {
				T[count].dad = lastPop;
				T[T[count].dad].Right = count;
			}
			else if (i != 0) {
				T[count].dad = lastPush;
				T[T[count].dad].Left = count;
			}
			lastPush = count;
			count++;
			isPop = false;
		}
		if (c == 'o') {
			cin >> cc;
			lastPop = l.top();
			l.pop();
			isPop = true;
		}
	}
	return 0;
}

void postorder(Tree root)
{
	if(TR[root].Left!=Null)
		postorder(TR[root].Left);
	if(TR[root].Right!=Null)
		postorder(TR[root].Right);
	q.push(TR[root].Data);
}

void printqueue()
{
	int n = q.size();
	for (int i = 0; i < n - 1; i++) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << q.front();
}