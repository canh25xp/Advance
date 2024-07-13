#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

const int N_MAX = 30;

int EasyLevel(const int (&nums)[N_MAX], int N);
int HardLevel(const int (&nums)[N_MAX], int N);
int HardLevel(const int (&nums)[N_MAX], int (&hard)[N_MAX][N_MAX], int N, int left, int right);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int nums[N_MAX] = {};
        for (int i = 0; i < N; i++)
            cin >> nums[i];

        cout << "Case #" << t + 1 << endl
             << EasyLevel(nums, N) << " " << HardLevel(nums, N) << endl;
    }

    return 0;
}

int EasyLevel(const int (&nums)[N_MAX], int N) {
    int you = 0, com = 0;
    bool your_turn = true;

    int left = 0, right = N - 1;

    while (left < right) {
        if (your_turn) {
            if (nums[left] >= nums[right]) {
                you += nums[left++];
            } else {
                you += nums[right--];
            }
        } else {
            if (nums[left] >= nums[right]) {
                com += nums[right--];
            } else {
                com += nums[left++];
            }
        }
        your_turn = !your_turn;
    }

    return you;
}

int HardLevel(const int (&nums)[N_MAX], int N) {
    int hard[N_MAX][N_MAX] = {};
    return HardLevel(nums, hard, N, 0, N - 1);
}

int HardLevel(const int (&nums)[N_MAX], int (&hard)[N_MAX][N_MAX], int N, int left, int right) {
    if (left > right)
        return 0;

    if (hard[left][right])
        return hard[left][right];

    int s1 = nums[left] + HardLevel(nums, hard, N, left + 1, right - 1);
    int s2 = nums[left] + HardLevel(nums, hard, N, left + 2, right);
    int s3 = nums[right] + HardLevel(nums, hard, N, left + 1, right - 1);
    int s4 = nums[right] + HardLevel(nums, hard, N, left, right - 2);

    hard[left][right] = MAX(MIN(s1, s2), MIN(s3, s4));

    return hard[left][right];
}