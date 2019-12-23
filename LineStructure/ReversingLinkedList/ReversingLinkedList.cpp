#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct ListNode *LinkedList;
struct ListNode {
	int Address;
	int Data;
	int NeAdr;
	LinkedList Next;
};

LinkedList ReadList();
LinkedList ReLink(LinkedList L);
void PrintList(LinkedList L);

int main() {
	LinkedList L = ReadList();
	//cout << endl;
	//PrintList(L);
	LinkedList RL = ReLink(L);
	PrintList(RL);
	return 0;
}

LinkedList ReadList(){
	LinkedList L = (LinkedList)malloc(sizeof(struct ListNode));
	int start, num, k;
	cin >> start >> num >> k;
	L->Address = -num - 1;
	L->Data = k;
	L->NeAdr = start;
	L->Next = NULL;
	LinkedList L1 = L;
	for (int i = 0; i < num; i++) {
		int ta, td, tn;
		cin >> ta >> td >> tn;
		LinkedList Ltemp = (LinkedList)malloc(sizeof(struct ListNode));
		Ltemp->Address = ta;
		Ltemp->Data = td;
		Ltemp->NeAdr = tn;
		Ltemp->Next = NULL;
		L1->Next = Ltemp;
		L1 = L1->Next;
	}
	LinkedList LOut = (LinkedList)malloc(sizeof(struct ListNode));
	LOut->Address = L->Address;
	LOut->Data = L->Data;
	LOut->NeAdr = L->NeAdr;
	LOut->Next = NULL;
	LinkedList L2 = LOut;
	L1 = L;
	bool flag = true;
	while (L2) {
		while (L1->Next&&flag) {
			if (L2->NeAdr == -1) {
				L2->Next = NULL;
				L1->Next = NULL;
			}
			else if (L2->NeAdr == L1->Next->Address) {
				L2->Next = L1->Next;
				L1->Next = L1->Next->Next;
				flag = false;
			}
			else {
				if (L1->Next->Next)
					L1 = L1->Next;
				else
					L1->Next = NULL;
			}
		}
		L1 = L;
		if (L2->Next)
			L2 = L2->Next;
		else
			break;
		flag = true;
	}
	
	return LOut;
}

LinkedList ReLink(LinkedList L) {
	LinkedList L1 = L;
	LinkedList LOut = (LinkedList)malloc(sizeof(struct ListNode));
	LOut->Address = L->Address;
	LOut->Data = L->Data;
	LOut->NeAdr = L->NeAdr;
	LOut->Next = NULL;
	LinkedList L2 = LOut;
	int k = L->Data;
	int n = -L->Address - 1;
	for (int i = 0; i < n / k; i++) {
		LinkedList Ltemp = (LinkedList)malloc(sizeof(struct ListNode));
		LinkedList Ltt = Ltemp;
		for (int j = 0; j < k; j++) {
			L1 = L;
			for (int ii = 0; ii < (i + 1) * k - j; ii++)
				L1 = L1->Next;
			LinkedList Lttemp = (LinkedList)malloc(sizeof(struct ListNode));
			Lttemp->Address = L1->Address;
			Lttemp->Data = L1->Data;
			Lttemp->NeAdr = L1->NeAdr;
			Ltt->Next = Lttemp;
			Ltt = Ltt->Next;
		}
		Ltemp = Ltemp->Next;
		L2->Next = Ltemp;
		for (int ii = 0; ii < k; ii++)
			L2 = L2->Next;
	}
	L2 = LOut;
	L2 = L2->Next;
	for (int i = 0; i < n - 1; i++) {
		if (L2->Next) {
			L2->NeAdr = L2->Next->Address;
			L2 = L2->Next;
		}
		else
			L2->NeAdr = -1;
	}
	return LOut;
}

void PrintList(LinkedList L){
	int n = -L->Address - 1;
	for (int i = 0; i < n - 1; i++) {
		if (L->Next)
			L = L->Next;
		printf("%05d %d %05d\n", L->Address, L->Data, L->NeAdr);
	}
	L = L->Next;
	printf("%05d %d -1\n", L->Address, L->Data);
	//system("pause");
}