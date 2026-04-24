#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20
#define INFI 32768
typedef enum{DG,DN,UDG,UDN}Graphkind; //DG：有向图。DN:有向网。UDG:无向图。UDN：无向网。
typedef char VertexData;
typedef int VRType;

typedef struct {
	VertexData vertex[MAX_VERTEX_NUM];//顶点向量
	VRType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
	int vexnum, arcnum;//图的当前顶点数和弧数
	Graphkind kind;//图的种类标志
}AdjMatrix;

int LocateVertex(AdjMatrix* G, VertexData v) {
	int i;
	for (i = 0; i < G->vexnum; i++) {
		if (G->vertex[i] == v)
			return i;
	}
	return -1;
}

void CreateGraph(AdjMatrix *G) {
	int i, j, e, weight;
	VertexData vx, vy;
	G->kind = UDN;
	printf("请输入顶点的个数，边（弧）的个数：");
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	getchar();
	printf("请输入各顶点（顶点之间不能有空格）：\n");
	for (i = 0; i < G->vexnum; i++)
		scanf("%c", &(G->vertex[i]));
	getchar();
	for (i = 0; i < G->vexnum; i++) {//将各条弧初始化
		for (j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = INFI;
	}
	printf("请输入各条边,每一条边输入两个顶点(边的两个顶点之间加一个空格)+边上的权值：\n");
	for (e = 0; e < G->arcnum; e++) {
		scanf("%c %c %d", &vx, &vy, &weight);
		getchar();
		i = LocateVertex(G, vx);
		j = LocateVertex(G, vy);
		G->arcs[i][j] = G->arcs[j][i] = weight;
	}
}

void Graph_kind(Graphkind x) {
	if (x == DG)
		printf("有向图\n");
	else if (x == DN)
		printf("有向网\n");
	else if (x == UDG)
		printf("无向图\n");
	else if (x == UDN)
		printf("无向网\n");
	else 
		printf("图的种类出错\n");
}

void PrintfGraph(AdjMatrix* G) {
	int i, j;
	printf("图的种类为：");
	Graph_kind(G->kind);
	printf("\n图中的各顶点为：\n");
	for (i = 0; i < G->vexnum; i++)
		printf("%c ", G->vertex[i]);
	printf("\n图的邻接矩阵为：\n");
	for (i = 0; i < G->vexnum; i++) {
		for (j = 0; j < G->vexnum; j++) {
			if (G->arcs[i][j] == INFI)
				printf("\t∞ ");
			else
				printf("\t%d ", G->arcs[i][j]);
		}
		printf("\n");
	}
}

void dfs(AdjMatrix* G, int i, int visited[]) {
	int w;
	printf("%c ", G->vertex[i]);
	visited[i] = 1;
	for (w = 0; w < G->vexnum; w++) {
		if (G->arcs[i][w] != INFI) {
			if (visited[w] == 0)
				dfs(G, w, visited);
		}
	}
}

void DFS_Graph(AdjMatrix* G) {
	int i, visited[MAX_VERTEX_NUM];
	printf("图的深度优先遍历序列为：");
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	for (i = 0; i < G->vexnum; i++) {
		if (visited[i] == 0)
			dfs(G, i, visited);
	}
	printf("\n");
}

typedef int QElemType;
#define MAXSIZE 100
#include "作业8(1)queue.h"
void BFS_Graph(AdjMatrix* G) {
	int i, visited[MAX_VERTEX_NUM], u, w;
	SeqQueue Q;
	printf("图的广度优先遍历序列为：");
	for (i = 0; i < G->vexnum; i++)
		visited[i] = 0;
	InitQueue(&Q);
	for (i = 0; i < G->vexnum; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			printf("%c", G->vertex[i]);
			EnterQueue(&Q, i);
			while (!_IsEmpty(&Q)) {
				DeleteQueue(&Q, &u);
				for (w = 0; w < G->vexnum; w++) {
					if (G->arcs[u][w] != INFI && !visited[w]) {
						visited[w] = 1;
						printf("%c", G->vertex[w]);
						EnterQueue(&Q, w);
					}
				}
			}
		}
	}
}

int main() {
	AdjMatrix G1;//4 5 ABCD A B 10 A C 6 A D 5 B D 15 C D 4
	CreateGraph(&G1);
	PrintfGraph(&G1);
	DFS_Graph(&G1);
	BFS_Graph(&G1);
	return 0;
}