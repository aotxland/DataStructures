#include<iostream>
#include<queue>
using namespace std;

#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */
bool Visited[MaxVertexNum];

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* 顶点数 */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
	DataType Data[MaxVertexNum];      /* 存顶点的数据 */
	/* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */

MGraph CreateGraph(int VertexNum)
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
	for (V = 1; V < Graph->Nv + 1; V++)
		for (W = 1; W < Graph->Nv + 1; W++)
			Graph->G[V][W] = 0;

	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = 1;
	/* 若是无向图，还要插入边<V2, V1> */
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