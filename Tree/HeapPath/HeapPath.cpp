#include<iostream>
using namespace std;

#define ElementType int
typedef struct HNode *Heap; /* 堆的类型定义 */
struct HNode {
	ElementType *Data; /* 存储元素的数组 */
	int Size;          /* 堆中当前元素个数 */
	int Capacity;      /* 堆的最大容量 */
};
typedef Heap MinHeap; /* 最小堆 */

#define MINDATA -10001

MinHeap CreateHeap(int MaxSize)
{ /* 创建容量为MaxSize的空的最小堆 */

	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MINDATA; /* 定义"哨兵"为大于堆中所有可能元素的值*/

	return H;
}

void PercDown(MinHeap H, int p)
{ /* 下滤：将H中以H->Data[p]为根的子堆调整为最xiao堆 */
	int Parent, Child;
	ElementType X;

	X = H->Data[p]; /* 取出根结点存放的值 */
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] > H->Data[Child + 1]))
			Child++;  /* Child指向左右子结点的较大者 */
		if (X <= H->Data[Child]) break; /* 找到了合适位置 */
		else  /* 下滤X */
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

void BuildHeap(MinHeap H)
{ /* 调整H->Data[]中的元素，使满足最小堆的有序性  */
  /* 这里假设所有H->Size个元素已经存在H->Data[]中 */

	int i;

	/* 从最后一个结点的父节点开始，到根结点1 */
	for (i = H->Size / 2; i > 0; i--)
		PercDown(H, i);
}

int main() {
	int n, m;
	cin >> n >> m;
	Heap H = CreateHeap(n);
	for (int i = 1; i < n + 1; i++) {
		int t;
		cin >> t;
		H->Data[i] = t;
	}
	BuildHeap(H);
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		while (t != 1) {
			cout << H->Data[t] << " ";
			t /= 2;
		}
		cout << H->Data[t] << endl;
	}
	system("pause");
}