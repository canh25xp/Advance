#include <iostream>

const int N = 5;
const int M = N;
const int INF = ~(1 << 31);

// Direction : up, down, left, right
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};

struct Point {
    int i, j;

    Point() : i(), j() {}

    Point(int i, int j) : i(i), j(j) {}

    bool valid(const Point &Size) const {
        return i >= 0 && j >= 0 && i < Size.i && j < Size.j;
    }

    bool valid(const int n, const int m) const {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
};

template <typename T, int MAX>
class Queue {
public:
    Queue() : front(-1), rear(-1) {}

    void push(T a) {
        data[++rear] = a;
    }

    T pop() {
        return data[++front];
    }

    bool empty() const {
        return front == rear;
    }

private:
    int front, rear;
    T data[MAX];
};

int solve(int (&)[N][M], int, int);

// Count number of land, start from the highest point in the map
int countLand(int (&)[N][M], int (&)[N][M], int, int, Point);

// raise water to a certain level, return the number of points got cover in water.
int raiseWater(int (&)[N][M], int (&)[N][M], int, int, int);

int spreadWater(int (&)[N][M], int (&)[N][M], int, int, Point, int);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int t = 0;
    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n & !m)
            break;

        int mat[N][M] = {};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        cout << "Case " << ++t << ": ";
        int ans = solve(mat, n, m);
        if (ans == -1)
            cout << "Island never splits.\n";
        else
            cout << "Island splits when ocean rises " << ans << " feet.\n";
    }

    return 0;
}

int solve(int (&map)[N][M], int n, int m) {
    int lowest = INF;
    int highest = 0;
    Point highestPoint;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > highest) {
                highest = map[i][j];
                highestPoint = Point(i, j);
            }
            if (map[i][j] && map[i][j] < lowest)
                lowest = map[i][j];
        }
    }

    for (int level = lowest; level < highest; level++) {
        int under[N][M] = {};
        int water = raiseWater(map, under, n, m, level);
        int land = countLand(map, under, n, m, highestPoint);
        if (land + water != n * m)
            return level;
    }

    return -1; // level must be equal to highest by now.
}

int countLand(int (&map)[N][M], int (&under)[N][M], int n, int m, Point start) {
    int visited[N][M] = {};
    int cnt = 1;
    Queue<Point, N * M> q;
    q.push(start);
    visited[start.i][start.j] = 1;
    while (!q.empty()) {
        Point curr = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next = Point(curr.i + di[d], curr.j + dj[d]);
            if (!next.valid(n, m) || visited[next.i][next.j] || under[next.i][next.j])
                continue;

            cnt++;
            visited[next.i][next.j] = 1;
            q.push(next);
        }
    }

    return cnt;
}

int raiseWater(int (&map)[N][M], int (&under)[N][M], int n, int m, int level) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (map[i][0] <= level && !under[i][0]) // left collumn
            cnt += spreadWater(map, under, n, m, Point(i, 0), level);

        if (map[i][m - 1] <= level && !under[i][m - 1]) // right edge
            cnt += spreadWater(map, under, n, m, Point(i, m - 1), level);
    }

    for (int i = 1; i < m - 1; i++) {
        if (map[0][i] <= level && !under[0][i]) // top edge
            cnt += spreadWater(map, under, n, m, Point(0, i), level);

        if (map[n - 1][i] <= level && !under[n - 1][i]) // bottom edge
            cnt += spreadWater(map, under, n, m, Point(n - 1, i), level);
    }

    return cnt;
}

int spreadWater(int (&map)[N][M], int (&under)[N][M], int n, int m, Point start, int level) {
    Queue<Point, M * N> q;
    q.push(start);
    under[start.i][start.j] = 1;
    int cnt = 1;
    while (!q.empty()) {
        Point curr = q.pop();
        for (int d = 0; d < 4; d++) {
            Point next = Point(curr.i + di[d], curr.j + dj[d]);
            if (!next.valid(n, m) || under[next.i][next.j] || map[next.i][next.j] > level)
                continue;

            cnt++;
            under[next.i][next.j] = 1;
            q.push(next);
        }
    }

    return cnt;
}