#include<iostream>
#include<vector>

using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

int Attach(int c, int e, Polynomial *pRear) {
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c; /* 对新结点赋值 */
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P; /* 修改pRear值 */
	return 0;
}

Polynomial PolyRead() {
	Polynomial P, Rear, t;
	int c, e, N;
	cin >> N;
	P = (Polynomial)malloc(sizeof(struct PolyNode)); /* 链表头空结点 */
	P->link = NULL;
	Rear = P;
	while (N--) {
		cin >> c;
		cin >> e;
		Attach(c, e, &Rear); /* 将当前项插入多项式尾部 */
	}
	t = P; P = P->link; free(t); /* 删除临时生成的头结点 */
	return P;

}

Polynomial add(Polynomial P1, Polynomial P2) {
	Polynomial Sum, t;
	Sum = (Polynomial)malloc(sizeof(struct PolyNode)); /* 链表头空结点 */
	Sum->link = NULL;
	t = Sum;
	while (P1 || P2) {
		if (!P1) {
			Attach(P2->coef, P2->expon, &t);
			P2 = P2->link;
		}
		else if (!P2) {
			Attach(P1->coef, P1->expon, &t);
			P1 = P1->link;
		}
		else if (P1->expon < P2->expon) {
			Attach(P2->coef, P2->expon, &t);
			P2 = P2->link;
		}
		else if (P1->expon > P2->expon) {
			Attach(P1->coef, P1->expon, &t);
			P1 = P1->link;
		}
		else if (P1->expon == P2->expon) {
			Attach(P1->coef + P2->coef, P2->expon, &t);
			P1 = P1->link;
			P2 = P2->link;
		}
	}
	t = Sum; Sum = Sum->link; 
	t = Sum;
	if (Sum->coef == 0)
		Sum = Sum->link;
	while (t) {
		if (t->link && t->link->coef == 0) {
			t->link = t->link->link;
		}
		t = t->link;
	}
	free(t); /* 删除临时生成的头结点 */
	return Sum;
}

Polynomial multi(Polynomial P1, Polynomial P2) {
	if (!P1 || !P2) return NULL;
	Polynomial Sum, t, t1, t2;
	Sum = (Polynomial)malloc(sizeof(struct PolyNode)); /* 链表头空结点 */
	Sum->link = NULL;
	t = Sum;
	t1 = P1;
	t2 = P2;
	//计算sum初始值
	while (t2) {
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, &t);
		t2 = t2->link;
	}
	//把后面的值插入中间
	t1 = P1;
	t = Sum;
	t1 = t1->link;
	while (t1) {
		t2 = P2;
		t = Sum;
		while (t2) {
			while (t->link && t->link->expon > t1->expon + t2->expon)//判断指数大小
				t = t->link;
			if (t->link && t->link->expon == t1->expon + t2->expon) {
				t = t->link;
				t->coef += t1->coef * t2->coef;
			}			else {				Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));				temp->coef = t1->coef * t2->coef;				temp->expon = t1->expon + t2->expon;				temp->link = t->link;				t->link = temp;				t = t->link;			}			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t = Sum; Sum = Sum->link; free(t);  /* 删除临时生成的头结点 */
	t1 = Sum;
	if (Sum->coef == 0)
		Sum = Sum->link;
	while (t1) {
		if (t1->link && t1->link->coef == 0){
			t1->link = t1->link->link;
		}
		t1 = t1->link;
	}
	return Sum;
}

void PrintPoly(Polynomial P)
{ /* 输出多项式 */
	int flag = 0; /* 辅助调整输出格式用 */
	if (!P) { printf("0 0\n"); return; }
	while (P) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}
int main() {
	Polynomial P1 = PolyRead();
	Polynomial P2 = PolyRead();
	PrintPoly(multi(P1, P2));
	PrintPoly(add(P1, P2));
	system("pause");
	return 0;
}