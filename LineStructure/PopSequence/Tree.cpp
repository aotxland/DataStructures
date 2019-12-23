#include<iostream>
#include "Tree.h"



Tree::Tree()
{
}


Tree::~Tree()
{
}

BinTree Tree::Insert(BinTree BST, ElementType X)
{
	if (!BST) {
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Left = NULL;
		BST->Right = NULL;
		BST->Data = X;
	}
	else if (X < BST->Data) {
		BST->Left = Insert(BST->Left, X);
	}
	else if (X > BST->Data) {
		BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

BinTree Tree::Delete(BinTree BST, ElementType X)
{
	BinTree t = Find(BST, X);
	free(t);
	return BST;
}

Position Tree::Find(BinTree BST, ElementType X)
{
	if (!BST) {
		return NULL;
	}
	else if (X < BST->Data) {
		BST->Left = Find(BST->Left, X);
	}
	else if (X > BST->Data) {
		BST->Right = Find(BST->Right, X);
	}
	return BST;
}

Position Tree::FindMin(BinTree BST)
{
	if (BST) {
		while (BST->Left != NULL) {
			BST = BST->Left;
		}
	}
	return BST;
}

Position Tree::FindMax(BinTree BST)
{
	if (BST) {
		while (BST->Right != NULL) {
			BST = BST->Right;
		}
	}
	return BST;
}
