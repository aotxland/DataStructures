#pragma once

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
class Tree
{
public:
	Tree();
	 ~Tree();
	 BinTree Insert(BinTree BST, ElementType X);
	 BinTree Delete(BinTree BST, ElementType X);
	 Position Find(BinTree BST, ElementType X);
	 Position FindMin(BinTree BST);
	 Position FindMax(BinTree BST);
};

