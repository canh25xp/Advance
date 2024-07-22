#pragma warning(disable : 4996)
#include "stack.hpp"
#include <iostream>

const int STACK_SIZE = 25;
const int MAX_SIZE = 5;

struct Pair {
    Pair();
    Pair(int x, int y);
    int x;
    int y;
};

template <int max_size>
int contiguous_count(const int (&matrix)[max_size][max_size], const int &value, const int &size);

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N = 0;
        cin >> N;

        int matrix[MAX_SIZE][MAX_SIZE] = {};

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                int x, y;
                cin >> x >> y;
                matrix[x - 1][y - 1] = i + 1;
            }
        }

        bool flag = true;

        for (int i = 0; i < N; i++) {
            int count = contiguous_count<MAX_SIZE>(matrix, i, N);
            if (count < N) {
                flag = false;
                break;
            }
        }

        cout << "Case #" << t + 1 << endl;
        (flag) ? cout << "good" << endl : cout << "wrong" << endl;
    }

    return 0;
}

template <int max_size>
int contiguous_count(const int (&matrix)[max_size][max_size], const int &value, const int &size) {
    bool checked[max_size][max_size] = {};
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == value) {
                Stack<Pair, STACK_SIZE> s;
                Pair pair(i, j);
                s.push(pair);
                checked[i][j] = true;
                count++;
                while (!s.empty()) {
                    pair = s.pop();
                    for (int d = 0; d < 4; d++) {
                        Pair new_pair(pair.x + dx[d], pair.y + dy[d]);
                        if (new_pair.x >= 0 && new_pair.x < size && new_pair.y >= 0 && new_pair.y < size && matrix[new_pair.x][new_pair.y] == value && checked[new_pair.x][new_pair.y] == 0) {
                            s.push(new_pair);
                            checked[new_pair.x][new_pair.y] = 1;
                            count++;
                        }
                    }
                }
                return count;
            }
        }
    }
    return count;
}

Pair::Pair() {
    x = 0;
    y = 0;
}

Pair::Pair(int _x, int _y) {
    x = _x;
    y = _y;
}
