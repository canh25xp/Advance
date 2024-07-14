////Tan cong thanh tri - Prim
#include <stdio.h>

#define MAX_N 101

int adjList[MAX_N][MAX_N];
int adjCnt[MAX_N];
int adjMap[MAX_N][MAX_N];
int N;

int parent[MAX_N], key[MAX_N];
bool visited[MAX_N];

int findMax() {
    int ret = -1;
    int max = -1;
    for (int v = 0; v < N; v++) {
        if (!visited[v] && key[v] > max) {
            max = key[v];
            ret = v;
        }
    }
    return ret;
}

int main() {
    int T;
    int u, v, machine, neighbor, total, remain;
    freopen("thanhtri_input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        total = 0;
        for (int i = 0; i < N; i++) {
            visited[i] = false;
            key[i] = -1;
            parent[i] = -1;
            for (int j = 0; j < N; j++)
                adjMap[i][j] = 0;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &u, &machine, &neighbor);
            adjCnt[u] = neighbor;
            for (int j = 0; j < neighbor; j++) {
                scanf("%d", &v);
                total += machine;
                adjMap[u][v] += machine;
                adjMap[v][u] = adjMap[u][v];
                adjList[u][j] = v;
            }
        }

        key[0] = 0;
        for (int i = 0; i < N - 1; i++) {
            u = findMax();
            if (u != -1) {
                visited[u] = true;
                for (int j = 0; j < adjCnt[u]; j++) {
                    v = adjList[u][j];
                    if (!visited[v] && adjMap[u][v] > key[v]) {
                        key[v] = adjMap[u][v];
                        parent[v] = u;
                    }
                }
            } else {
                for (u = 0; u < N; u++) {
                    if (!visited[u])
                        break;
                }
                key[u] = 0;
                i--;
            }
        }
        remain = 0;
        for (int i = 1; i < N; i++) {
            if (parent[i] != -1)
                remain += adjMap[i][parent[i]];
        }
        printf("%d\n", total - remain);
    }

    return 0;
}

// Tan cong thanh tri - Kruskal
// #include <stdio.h>
//
// #define MAX_N 101
//
// int adjMap[MAX_N][MAX_N];
// int st[MAX_N * MAX_N];
// int en[MAX_N * MAX_N];
// int dist[MAX_N * MAX_N];
// int edgeCnt;
// int N;
//
// int parent[MAX_N];
//
// void swap(int i, int j)
//{
//	int tmp = st[i]; st[i] = st[j]; st[j] = tmp;
//	tmp = en[i]; en[i] = en[j]; en[j] = tmp;
//	tmp = dist[i]; dist[i] = dist[j]; dist[j] = tmp;
// }
//
// void qSort(int left, int right)
//{
//	int i, last;
//	if (left >= right)
//		return;
//	swap(left, (left + right) >> 1);
//	last = left;
//	for (int i = left + 1; i <= right; i++)
//		if (dist[i] > dist[left])
//			swap(++last, i);
//	swap(left, last);
//	qSort(left, last - 1);
//	qSort(last + 1, right);
// }
//
// int findSet(int x)
//{
//	if (x == parent[x])
//		return x;
//	return parent[x] = findSet(parent[x]);
// }
//
// void join(int x, int y) {
//	parent[findSet(y)] = findSet(x);
// }
//
// int main() {
//	int T;
//	int res;
//	int u, v, machine, neighbor, ret;
//	freopen("thanhtri_input.txt", "r", stdin);
//	scanf("%d", &T);
//
//	for (int tc = 1; tc <= T; tc++) {
//		scanf("%d", &N);
//		edgeCnt = 0;
//		ret = 0;
//		for (int i = 0; i < N; i++) {
//			parent[i] = i;
//			for (int j = 0; j < N; j++)
//				adjMap[i][j] = 0;
//		}
//		for (int i = 0; i < N; i++) {
//			scanf("%d%d%d", &u, &machine, &neighbor);
//			for (int j = 0; j < neighbor; j++) {
//				scanf("%d", &v);
//				adjMap[u][v] += machine;
//				adjMap[v][u] = adjMap[u][v];
//			}
//		}
//
//		for (int i = 0; i < N; i++) {
//			for (int j = i + 1; j < N; j++) {
//				if (adjMap[u][v]) {
//					dist[edgeCnt] = adjMap[u][v];
//					st[edgeCnt] = v;
//					en[edgeCnt++] = u;
//				}
//			}
//		}
//
//		qSort(0, edgeCnt - 1);
//
//		for (int i = 0; i < edgeCnt; i++) {
//			u = findSet(st[i]);
//			v = findSet(en[i]);
//			if (u == v)
//				ret += dist[i];
//			else
//				join(u, v);
//
//		}
//		printf("%d\n", ret);
//	}
//
//	return 0;
// }

// Tan cong thanh tri - DFS
#include <stdio.h>

#define MAX_N 101
int adjMap[MAX_N][MAX_N];
int N;

int parent[MAX_N];
bool visited[MAX_N];
int ret;

bool hasCycle;
int cnt;
int st[MAX_N];
void DFS(int v) {
    if (hasCycle)
        return;
    for (int i = 0; i < N; ++i) {
        if (adjMap[v][i]) {
            if (visited[i]) {
                if (i == parent[v])
                    continue;

                hasCycle = true;
                parent[i] = v;

                int k = i, minVal = adjMap[v][i];
                int curr = v;
                while (curr != i) {
                    if (adjMap[curr][parent[curr]] < minVal) {
                        k = curr;
                        minVal = adjMap[curr][parent[curr]];
                    }
                    curr = parent[curr];
                }
                ret += adjMap[k][parent[k]];
                adjMap[k][parent[k]] = adjMap[parent[k]][k] = 0;
                return;
            } else {
                visited[i] = true;
                parent[i] = v;
                DFS(i);
            }
            if (hasCycle)
                break;
        }
    }
}

int main() {
    int T;
    int u, v, machine, neighbor;
    freopen("thanhtri_input.txt", "r", stdin);
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                adjMap[i][j] = 0;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &u, &machine, &neighbor);
            for (int j = 0; j < neighbor; j++) {
                scanf("%d", &v);
                adjMap[u][v] += machine;
                adjMap[v][u] = adjMap[u][v];
            }
        }

        do {
            hasCycle = false;
            for (int i = 0; i < N; ++i) {
                visited[i] = false;
                parent[i] = -1;
            }
            for (int i = 0; i < N; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    DFS(i);
                }
                if (hasCycle)
                    break;
            }
        } while (hasCycle);
        printf("%d\n", ret);
    }

    return 0;
}