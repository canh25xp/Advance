#pragma warning(disable : 4996)
#include <iostream>

namespace utils {
double epsilon = 1e-6;

// Calculate cube root using Newton-Raphon method.
double cbrt(double x);

// Calculate cube root using Binary search.
double cbrt_binary(double x);

double abs(double x);
} // namespace utils

int solve(int N);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    const char *output = "myoutput.txt";
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);

    int T; // Totol number of Test cases
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        cout << "#" << t + 1 << " " << solve(N) << endl;
    }

    return 0;
}

int solve(int N) {
    using utils::cbrt;
    int count = 0;
    int limit = static_cast<int>(cbrt(N)); // upper bound for cube root

    for (int a = 0; a <= limit; a++)
        for (int b = a; b <= limit; b++)
            for (int c = b; c <= limit; c++)
                for (int d = c; d <= limit; d++)
                    for (int e = d; e <= limit; e++)
                        if (a * a * a + b * b * b + c * c * c + d * d * d + e * e * e == N)
                            count++;

    return count;
}

double utils::cbrt_binary(double x) {
    double low = 0;
    double high = x;
    double mid;

    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid * mid > x)
            high = mid;
        else
            low = mid;
    }

    return low;
}

double utils::cbrt(double x) {
    if (x == 0)
        return 0;

    double guess = x;

    while (true) {
        double next_guess = (2.0 * guess + x / (guess * guess)) / 3.0;
        if (abs(guess - next_guess) < epsilon)
            break;

        guess = next_guess;
    }

    return guess;
}

double utils::abs(double x) {
    return (x < 0) ? -x : x;
}