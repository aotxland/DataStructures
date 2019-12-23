#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 100    /* ��󶥵�����Ϊ100 */
typedef int Vertex;         /* �ö����±��ʾ����,Ϊ���� */
typedef int WeightType;        /* �ߵ�Ȩֵ��Ϊ���� */
typedef char DataType;        /* ����洢������������Ϊ�ַ��� */
bool Visited[MaxVertexNum];

/* �ߵĶ��� */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* �����<V1, V2> */
};
typedef PtrToENode Edge;

/* ͼ���Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* ������ */
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
	/* ��ʼ���ڽӾ��� */
	/* ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv - 1) */
	for (V = 1; V < Graph->Nv + 1; V++)
		for (W = 1; W < Graph->Nv + 1; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* ����� <V1, V2> */
	Graph->G[E->V1][E->V2] = 1;
	/* ��������ͼ����Ҫ�����<V2, V1> */
	Graph->G[E->V2][E->V1] = 1;
}

bool IsEdge(MGraph Graph, Vertex V, Vertex W)
{
	return Graph->G[V][W] == 1 ? true : false;
}


int BFS(MGraph Graph, Vertex S){ 
	int count = 1;
	int level = 0;
	int last = S;
	int tail;
	queue <int> q;
	q.push(S);
	Visited[S] = 1;
	while (!q.empty()) {
		int v;
		v = q.front();
		q.pop();
		for (int i = 1; i < Graph->Nv + 1; i++) {
			if (!Visited[i] && IsEdge(Graph, v, i)) {
				Visited[i] = 1;
				q.push(i);
				count++;
				tail = i;
			}
		}
		if (v == last) {
			level++;
			last = tail;
		}
		if (level == 6) {
			break;
		}
	}
	return count;
}

int main() {
	int n, m;
	cin >> n >> m;
	MGraph g = CreateGraph(n);
	for (int i = 0; i < m; i++) {
		Edge e;
		e = (Edge)malloc(sizeof(struct ENode));
		int a, b;
		cin >> a >> b;
		e->V1 = a;
		e->V2 = b;
		InsertEdge(g, e);
	}
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) Visited[j] = 0;
		double ans = (double)BFS(g, i) / n * 100;
		printf("%d: %.2f%%\n", i, ans);
	}
	system("pause");
	return 0;
}