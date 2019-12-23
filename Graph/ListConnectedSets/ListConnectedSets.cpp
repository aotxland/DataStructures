#include<iostream>
#include<queue>
using namespace std;
/* ͼ���ڽӾ����ʾ�� */

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
#define INFINITY 65535        /* ����Ϊ˫�ֽ��޷������������ֵ65535*/
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */
int Visited[MaxVertexNum];

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* �����<V1, V2> */
	WeightType Weight;  /* Ȩ�� */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* ������ */
	int Ne;  /* ����   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* �ڽӾ��� */
	DataType Data[MaxVertexNum];      /* �涥������� */
	/* ע�⣺�ܶ�����£����������ݣ���ʱData[]���Բ��ó��� */
};
typedef PtrToGNode MGraph; /* ���ڽӾ���洢��ͼ���� */

MGraph CreateGraph(int VertexNum)
{ /* ��ʼ��һ����VertexNum�����㵫û�бߵ�ͼ */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* ����ͼ */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->G[E->V2][E->V1] = E->Weight;
	Graph->Nv ++;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	scanf("%d", &Nv);   /* ���붥����� */
	Graph = CreateGraph(Nv); /* ��ʼ����Nv�����㵫û�бߵ�ͼ */

	scanf("%d", &(Graph->Ne));   /* ������� */
	if (Graph->Ne != 0) { /* ����б� */
		E = (Edge)malloc(sizeof(struct ENode)); /* �����߽�� */
		/* ����ߣ���ʽΪ"��� �յ� Ȩ��"�������ڽӾ��� */
		for (i = 0; i < Graph->Ne; i++) {
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� */
			InsertEdge(Graph, E);
		}
	}

	/* ������������ݵĻ����������� */
	for (V = 0; V < Graph->Nv; V++)
		scanf(" %c", &(Graph->Data[V]));

	return Graph;
}
bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] < INFINITY ? true : false;
}

/* Visited[]Ϊȫ�ֱ������Ѿ���ʼ��Ϊfalse */
void BFS(MGraph Graph, Vertex S, void(*Visit)(Vertex))
{   /* ��SΪ��������ڽӾ���洢��ͼGraph����BFS���� */
	queue<int> Q;
	Vertex V, W;
	
	//Q = CreateQueue(MaxSize); /* �����ն���, MaxSizeΪ�ⲿ����ĳ��� */
	/* ���ʶ���S���˴��ɸ��ݾ��������Ҫ��д */
	Visit(S);
	Visited[S] = true; /* ���S�ѷ��� */
	//AddQ(Q, S); /* S����� */
	Q.push(S);
	while (!Q.empty()) {
		V = Q.front();  /* ����V */
		Q.pop();
		for (W = 0; W < Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
			/* ��W��V���ڽӵ㲢��δ���ʹ� */
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				/* ���ʶ���W */
				Visit(W);
				Visited[W] = true; /* ���W�ѷ��� */
				Q.push(W); /* W����� */
			}
	} /* while����*/
}


int main() {
	int n, e;
	cin >> n >> e;
	MGraph M = CreateGraph(n);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		Edge edge;
		edge->V1 = a;
		edge->V2 = b;
		edge->Weight = 1;
		InsertEdge(M, edge);
	}

	queue<int> q1;

}