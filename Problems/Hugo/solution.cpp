#include <iostream>

using namespace std;

int t, tc, n, m, sx, sy, p, thoat, ans, front, rear;
int lakes[20][20], diamonds[20][20], qx[600], qy[600], fires[20][20], visited[20][20], gates[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void initQ() {
    rear = front = -1;
}

int isEmpty() {
    if (front == rear)
        return 1;
    return 0;
}

void enQueue(int x, int y) {
    rear++;
    qx[rear] = x;
    qy[rear] = y;
}

int deQueueX() {
    if (!isEmpty())
        return qx[front + 1];
    return -1;
}

int deQueueY() {
    if (!isEmpty()) {
        front++;
        return qy[front];
    }
    return -1;
}

int dk(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void chayLan() {
    initQ();
    int i, j, x, y, tx, ty, k;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (fires[i][j] == 0) {
                enQueue(i, j);
                // dchay[i][j] = 1;
            }
        }
    }
    while (!isEmpty()) {
        x = deQueueX();
        y = deQueueY();
        for (k = 0; k < 4; k++) {
            tx = x + dx[k];
            ty = y + dy[k];
            if (dk(tx, ty) && (fires[tx][ty] == 5000 || fires[tx][ty] > fires[x][y] + 1) && lakes[tx][ty] != 1) {
                enQueue(tx, ty);
                fires[tx][ty] = fires[x][y] + 1;
            }
        }
    }
}

void DFS(int i, int j, int time, int score) {
    int h = time;
    int c = score;

    if (gates[i][j] == 3) {
        if (c > ans)
            ans = c;
    }
    if (lakes[i][j] == 1)
        h = h + 2;
    else
        h = h + 1;

    for (int k = 0; k < 4; k++) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        if (dk(tx, ty) && visited[tx][ty] == 0 && (lakes[tx][ty] == 1 || h < fires[tx][ty])) {
            visited[tx][ty] = 1;
            DFS(tx, ty, h, c + diamonds[tx][ty]);
            visited[tx][ty] = 0;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n >> m >> sx >> sy;
        sx;
        sy;
        int i, j, x, h, c;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                lakes[i][j] = 0;
                fires[i][j] = 5000;
                visited[i][j] = 0;
                gates[i][j] = 0;
            }
        }
        cin >> p;
        for (x = 0; x < p; x++) {
            cin >> h >> c;
            fires[h][c] = 0;
        }
        cin >> p;
        for (x = 0; x < p; x++) {
            cin >> h >> c;
            lakes[h][c] = 1;
        }
        cin >> thoat;
        for (x = 0; x < thoat; x++) {
            cin >> h >> c;
            gates[h][c] = 3;
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> diamonds[i][j];
            }
        }

        chayLan();
        ans = -1;
        visited[sx][sy] = 1;
        if (lakes[sx][sy] != 2)
            DFS(sx, sy, 0, diamonds[sx][sy]);
        cout << "Case #" << tc << endl;
        cout << ans << endl;
    }
    return 0;
}