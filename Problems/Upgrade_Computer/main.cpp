#include <iostream>

const int N = 20;
const int M = 30;

int n, m, required, ans;
int price[50], discount_price[50], discount_part[50][30], required_part[50], bought[50];

void backtrack(int x, int tien);

using namespace std;
int main(int argc, char **argv) {
    const char *input = (argc > 1) ? argv[1] : "input.txt";
    freopen(input, "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> price[i];
            bought[i] = 0;
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                discount_part[i][j] = 0;
            }
        }
        for (int i = 1; i <= m; i++) {
            cin >> discount_price[i];
            int x;
            cin >> x;
            for (int j = 1; j <= x; j++) {
                int l;
                cin >> l;
                discount_part[i][l] = 1;
            }
        }

        cin >> required;
        for (int i = 1; i <= required; i++)
            cin >> required_part[i];

        ans = INT_MAX;
        backtrack(1, 0);

        cout << "#" << tc << " " << ans << endl;
    }
    return 0;
}

void backtrack(int x, int tien) {
    if (x == required + 1) {
        if (ans > tien)
            ans = tien;
        return;
    }
    int tb = required_part[x];
    if (bought[tb] == 0) {
        for (int j = 0; j <= 1; j++) {
            if (j == 0) {
                bought[tb]++;
                backtrack(x + 1, tien + price[tb]);
                bought[tb]--;
            } else {
                for (int k = 1; k <= m; k++) {
                    if (discount_part[k][tb]) {
                        for (int i = 0; i <= n; i++) {
                            if (discount_part[k][i])
                                bought[i]++;
                        }
                        backtrack(x + 1, tien + discount_price[k]);
                        for (int i = 1; i <= n; i++) {
                            if (discount_part[k][i])
                                bought[i]--;
                        }
                    }
                }
            }
        }
    } else {
        backtrack(x + 1, tien);
    }
}