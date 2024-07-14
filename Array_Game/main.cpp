#include <iostream>
using namespace std;

const int N_MAX = 20000;

int solve(const int (&arr)[N_MAX], const int &N);

int findMid(const int (&arr)[N_MAX], int left, int right, long long halfSum);

int backTrack(const int (&arr)[N_MAX], int left, int right, long long sum, int score, int &maxScore);

int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        int arr[N_MAX] = {};

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        cout << solve(arr, N) << endl;
    }

    return 0;
}

int solve(const int (&arr)[N_MAX], const int &N) {
    long long sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];

    // Special case where the array contains all zero
    if (sum == 0)
        return N - 1;

    int maxScore = 0;
    backTrack(arr, 0, N - 1, sum, 0, maxScore);
    return maxScore;
}

int findMid(const int (&arr)[N_MAX], int left, int right, long long halfSum) {
    long long temp = 0; //
    for (int mid = left;; mid++) {
        temp += arr[mid];
        if (temp == halfSum)
            return mid;
        else if (temp > halfSum)
            return -1;
    }
    return -1;
}

int backTrack(const int (&arr)[N_MAX], int left, int right, long long sum, int score, int &maxScore) {
    if (left == right || (sum % 2 == 1)) { // nếu có 1 phần tử hoặc tổng lẻ
        if (score > maxScore)
            maxScore = score;
        return maxScore;
    }

    // tìm vị trí mid sao cho tổng từ left đến mid bằng sum / 2
    int mid = findMid(arr, left, right, sum / 2);

    if (mid == -1) { // nếu không thể chia được
        if (score > maxScore)
            maxScore = score;
        return maxScore;
    }

    // lặp lại thao tác với 2 nửa, với số điểm + 1
    backTrack(arr, left, mid, sum / 2, score + 1, maxScore);
    backTrack(arr, mid + 1, right, sum / 2, score + 1, maxScore);

    return maxScore;
}
