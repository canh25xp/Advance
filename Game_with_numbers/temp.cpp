#include <iostream>
using namespace std;

const int N_MAX = 30;

int EasyLevel(int (&nums)[N_MAX], int N);
int HardLevel(int (&nums)[N_MAX], int N);

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
             << EasyLevel(nums, N) << " "
             << HardLevel(nums, N) << endl;
    }

    return 0;
}

int EasyLevel(int (&nums)[N_MAX], int N) {
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

int HardLevel(int (&nums)[N_MAX], int N) {
    return 0;
}
