#include <iostream>
using namespace std;

//二叉搜索树的表示
typedef struct TreeNode * Tree;
struct TreeNode {
	Tree Left, Right;
	int flag;  //该节点访问过的设为1
	int data;
};

Tree NewNode(int t) {
	Tree T;
	T = new struct TreeNode;
	T->flag = 0;
	T->Left = T->Right = NULL;
	T->data = t;
	return T;
}

Tree insert(int t, Tree T) {
	if (!T) {
		T = NewNode(t); //任何插入的第一步，要先判断是否为空
	}
	else
	{
		if (t > T->data) {
			T->Right = insert(t, T->Right);
		}
		else {
			T->Left = insert(t, T->Left);
		}
	}
	return T;
}

Tree BuildTree(int N) {
	Tree T;
	int t;
	cin >> t;
	T = NewNode(t);
	for (int i = 1; i < N; i++)
	{
		cin >> t;
		T = insert(t, T);
	}
	return T;
}

int check(Tree T, int t) {

	if (T->flag) { //该节点已经被查找过，到它的左子树或者右子树寻找
		if (t < T->data)return check(T->Left, t);
		else return check(T->Right, t);
	}
	else {
		if (T->data == t) {
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
}


int Judge(Tree T, int N) {//当发现某个序列不一致的时候，必须全部序列读完才return
	int t;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if ((!check(T, t)) && (!flag))
			flag = 1;
	}
	return (!flag);
}
void ResetT(Tree T) {
	if (T->Left) ResetT(T->Left);
	if (T->Right) ResetT(T->Right);
	T->flag = 0;
}
void FreeTree(Tree T) {
	if (T->Left) FreeTree(T->Left);
	if (T->Right) FreeTree(T->Right);
	free(T);
}

int main() {
	int N, L;
	cin >> N;
	while (N)
	{
		cin >> L;
		Tree T = BuildTree(N);
		for (int i = 0; i < L; i++)
		{
			if (Judge(T, N))cout << "Yes" << endl;
			else cout << "No" << endl;
			ResetT(T);//flag清零
		}
		FreeTree(T);//把树的节点释放掉
		cin >> N;
	}

	system("pause");
	return 0;
}