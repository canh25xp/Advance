#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N_MAX = 16;
const int M_MAX = 3000;
const int SIZE = 100000;

// Find maximum value of an array, but do not exceed the limit.
int find_max(int (&arr)[SIZE], int n, int limit);

int find_max_capacity(int (&arr)[N_MAX], int n, int limit);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int ti = 1; ti <= T; ++ti) {
        int loading_capacity, cows;
        cin >> loading_capacity >> cows;

        int weights[N_MAX] = {};

        for (int i = 0; i < cows; i++)
            cin >> weights[i];

        cout << "#" << ti << " " << find_max_capacity(weights, cows, loading_capacity) << endl;
    }
    return 0;
}

int find_max_capacity(int (&arr)[N_MAX], int n, int limit) {
    int cummcumulative_sum[SIZE] = {};

    int index = 0;
    for (int i = 0; i < n; i++) {
        cummcumulative_sum[index] = arr[i];
        index++;
        for (int j = index - 2; j >= 0; j--) {
            cummcumulative_sum[index] = arr[i] + cummcumulative_sum[j];
            index++;
        }
    }

    return find_max(cummcumulative_sum, index, limit);
}

int find_max(int (&arr)[SIZE], int n, int limit) {
    int max = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > max && arr[i] <= limit)
            max = arr[i];

    return max;
}