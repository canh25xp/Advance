namespace utils {
double epsilon = 1e-6;

// Calculate cube root using Newton-Raphon method.
double cbrt(double x);

// Calculate cube root using Binary search.
double cbrt_binary(double x);

double abs(double x);
} // namespace utils

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