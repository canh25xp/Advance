#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

const int MAX_N = 4; // Should be 30

int MinHard(const int (&num)[MAX_N], int (&hard)[MAX_N][MAX_N], int i, int j);
int MaxHard(const int (&num)[MAX_N], int (&hard)[MAX_N][MAX_N], int i, int j);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int N;
        cin >> N;
        int num[MAX_N] = {};
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }

        int hard[MAX_N][MAX_N] = {};

        int minHard = MinHard(num, hard, 0, N - 1);
        int maxHard = MaxHard(num, hard, 0, N - 1);

        cout << "Case #" << tc + 1 << endl;
        cout << minHard << " " << maxHard << endl;
    }
    return 0;
}

int MinHard(const int (&num)[MAX_N], int (&hard)[MAX_N][MAX_N], int i, int j) {
    return 0;
}

int MaxHard(const int (&num)[MAX_N], int (&hard)[MAX_N][MAX_N], int i, int j) {
    if (i > j)
        return 0;

    if (hard[i][j])
        return hard[i][j];

    int s1 = num[i] + MaxHard(num, hard, i + 1, j - 1);
    int s2 = num[i] + MaxHard(num, hard, i + 2, j);
    int s3 = num[j] + MaxHard(num, hard, i + 1, j - 1);
    int s4 = num[j] + MaxHard(num, hard, i, j - 2);

    hard[i][j] = MAX(MIN(s1, s2), MIN(s3, s4));

    return hard[i][j];
}
