#include<stdio.h> 
#define MAX_M 500
//Khai bao ctdl List
typedef struct {
	int data[MAX_M];
	int size;
}List;
void makeNullList(List *L) {
	L -> size = 0;
}
void pushBackList(List *L, int x) {
	L -> data[L -> size] = x;
	L -> size ++;
}
int elementAt(List *L, int i) {
	return L -> data[i -  1];
}
int countList(List *L) {
	return L -> size;
}
//Khai bao ctdl Queue
typedef struct {
	int data[MAX_M];
	int front, rear;
}Queue; 
void makeNullQueue(Queue *Q {
	Q -> front =  0;
	Q -> rear = -1;
}
void enqueue(Queue *Q, int u) {
	Q -> rear ++;
	Q -> data[Q -> rear] = u;
}
int front(Queue *Q) {
	return Q -> data[Q -> front]
}
void dequeue(Queue *Q) {
	Q -> front ++;
}
int empty(Queue *Q) {
	return Q -> front > Q -> rear;
}
//Khai bao ctdl Stack
typedef struct {
	int data[MAX_M];
	int top_idx;
}Stack;
void makeNullStack(Stack *S) {
	S -> top_idx = -1;
}
void pushBackStack(Stack *S, int u) {
	S -> top_idx ++;
	S -> data[S -> top_idx] = u;
}
int top(Stack *S) {
	return S -> data[S -> toop_idx];
}
void pop(Stack *S) {
	S -> top_idx --;
}
int empty(Stack *S) {
	return S -> top_idx == -1;
}
//Bieu dien do thi bang danh sach cung
typedef struct {
	int u, v; 
} Edge;
typedef struct {
	int n, m; 
	Edge edges[MAX_M]; 
} Graph;
//Bieu dien do thi bang ma tran ke
typedef struct {
	int n;
	int A[MAX_M][MAX_M];
} Graph1;
//Bieu dien do thi bang danh sach ke
typedef struct {
	int n; 
	List A[MAX_M];
} Graph2;
//Cac ham bieu dien bang danh sach cung
void init_graph(Graph *pG, int n) {
	pG->n = n; 
	pG->m = 0;
}
void add_edge(Graph *pG, int u, int v) {
	pG->edges[pG->m].u = u;
	pG->edges[pG->m].v = v;
	pG->m++;
}
int adjacent(Graph *pG, int u, int v) {
	int e;
	for (e = 0; e < pG->m; e++)
	if ((pG->edges[e].u == u && pG->edges[e].v == v) || (pG->edges[e].u == v && pG->edges[e].v == u))
		return 1;
	return 0;
}
int degree(Graph *pG, int u) {
	int e, deg_u = 0;
	for (e = 0; e < pG->m; e++) {
		if (pG->edges[e].u == u)
			deg_u++;
		if (pG->edges[e].v == u)
			deg_u++;
	}
	return deg_u;
}
void neighbours(Graph* pG, int u) {
	int e;
	for (e = 0; e < pG->m; e++)
		if (pG->edges[e].u == u)
			printf("%d ", pG->edges[e].v);
		printf("\n");
}
// Cach ham bieu dien bang ma tran ke
void init_graph(Graph *pG, int n) {
//n: d?nh, 0: cung
	pG->n = n;
	pG->m = 0;
//Kh?i t?o ma tr?n A ch?a toàn s? 0
	for (int u = 1; u <= n; u++)
		for (int v = 1; v <= n; v++)
			pG->A[u][v] = 0;

}
void add_edge(Graph *pG, int u, int v) {
	pG->A[u][v] = 1; //cho u k? v?i v
	pG->A[v][u] = 1; //cho v k? v?i u
//Tang s? cung lên 1
	pG->m++;
}
int adjacent(Graph *pG, int u, int v) {
	return pG->A[u][v] > 0;
}
int degree(Graph *pG, int u) {
	int deg_u = 0;
	for (int v = 1; v <= pG->n; v++)
		deg_u += pG->A[u][v];
	return deg_u;
}
void neighbours(Graph* pG, int u) {
	int v;
	for (v = 1; v <= pG->n; v++)
		if (pG->A[u][v] != 0)
			printf("%d ", v);
	printf("\n");
}
//Cac ham bieu dien bang danh sach ke
void init_graph(Graph *pG, int n) {
	int u;
	pG->n = n;
	//Kh?i t?o các danh sách k? r?ng
	for (u = 1; u <= n; u++)
		make_null(&pG->adj[u]);
}
void add_edge(Graph *pG, int u, int v) {
	push_back(&pG->adj[u], v); //v là k? c?a u
	push_back(&pG->adj[v], u); //u là k? c?a v
}
//Thêm cung e = (u, v) vào d? th? vô hu?ng *pG
int adjacent(Graph *pG, int u, int v) {
	int j;
	for (j = 1; j <= pG->adj[u].size; j++)
		if (element_at(&pG->adj[u], j) == v)
			return 1; //v n?m trong dánh sách adj[u]
	return 0; //v không có trong danh sách adj[u]
}
int degree(Graph *pG, int u) {
	return pG -> adj[u].size;
}
void neighbours(Graph* pG, int u) {
	int i;
	for(i = 1; i <= adj[u].size; i ++)
		printf("%d ", elementAt(adj[u]), i);
}
