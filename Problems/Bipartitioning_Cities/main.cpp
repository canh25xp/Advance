#include <iostream>
#include <queue>

const int T = 12;
const int N = 1000;

int adj[N][N] = {};

bool isBipartiteUtil(int (&G)[N][N], int V, int src, int (&colorArr)[N]);

bool isBipartite(int (&G)[N][N], int V);

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);

    for (int t = 0; t < T; t++) {
        int vertices, edges;
        cin >> vertices >> edges;
        for (int i = 0; i < edges; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << "#" << t + 1 << " ";
        cout << isBipartite(adj, vertices) << endl;
    }

    return 0;
}

bool isBipartite(int (&G)[N][N], int V) {
    // Create a color array to store colors assigned to all vertices.
    // Vertex/number is used as index in this array.
    // The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'.
    // The value 1 is used to indicate first color is assigned,
    // and value 0 indicates second color is assigned.
    int colorArr[N];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // This code is to handle disconnected graph
    for (int i = 0; i < V; i++)
        if (colorArr[i] == -1)
            if (!isBipartiteUtil(G, V, i, colorArr))
                return false;

    return true;
}

bool isBipartiteUtil(int (&G)[N][N], int V, int src, int (&colorArr)[N]) {
    queue<int> q;
    q.push(src);
    colorArr[src] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Return false if there is a self-loop
        if (G[u][u] == 1)
            return false;

        // Find all non-colored adjacent vertices
        for (int v = 0; v < V; ++v) {
            // An edge from u to v exists and
            // destination v is not colored
            if (G[u][v] && colorArr[v] == -1) {
                // Assign alternate color to this
                // adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            // An edge from u to v exists and destination
            // v is colored with same color as u
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can
    // be colored with alternate color
    return true;
}
