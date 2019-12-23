#include<iostream>
using namespace std;

#define ElementType int
typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
	ElementType *Data; /* �洢Ԫ�ص����� */
	int Size;          /* ���е�ǰԪ�ظ��� */
	int Capacity;      /* �ѵ�������� */
};
typedef Heap MinHeap; /* ��С�� */

#define MINDATA -10001

MinHeap CreateHeap(int MaxSize)
{ /* ��������ΪMaxSize�Ŀյ���С�� */

	MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
	H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
	H->Size = 0;
	H->Capacity = MaxSize;
	H->Data[0] = MINDATA; /* ����"�ڱ�"Ϊ���ڶ������п���Ԫ�ص�ֵ*/

	return H;
}

void PercDown(MinHeap H, int p)
{ /* ���ˣ���H����H->Data[p]Ϊ�����Ӷѵ���Ϊ��xiao�� */
	int Parent, Child;
	ElementType X;

	X = H->Data[p]; /* ȡ��������ŵ�ֵ */
	for (Parent = p; Parent * 2 <= H->Size; Parent = Child) {
		Child = Parent * 2;
		if ((Child != H->Size) && (H->Data[Child] > H->Data[Child + 1]))
			Child++;  /* Childָ�������ӽ��Ľϴ��� */
		if (X <= H->Data[Child]) break; /* �ҵ��˺���λ�� */
		else  /* ����X */
			H->Data[Parent] = H->Data[Child];
	}
	H->Data[Parent] = X;
}

void BuildHeap(MinHeap H)
{ /* ����H->Data[]�е�Ԫ�أ�ʹ������С�ѵ�������  */
  /* �����������H->Size��Ԫ���Ѿ�����H->Data[]�� */

	int i;

	/* �����һ�����ĸ��ڵ㿪ʼ���������1 */
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