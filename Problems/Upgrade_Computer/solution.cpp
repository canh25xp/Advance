#include<iostream>

using namespace std;

int t, tc, n, m, l, ans;
int price[50], discount_price[50], discount_part[50][30], required_part[50], bought[50];

void backtrack(int x, int tien){
    if (x == l + 1) {
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

int main() {
	freopen("input.txt", "r", stdin);
	cin >> t;
	for (tc = 1; tc <= t; tc++) {
		cin >> n;
		int i, j, x, l;
		for (i = 1; i <= n; i++) {
                    cin >> price[i];
                    bought[i] = 0;
                }
                cin >> m;
                for (i = 1; i <= m; i++) {
                    for (j = 1; j <= n; j++) {
                        discount_part[i][j] = 0;
                    }
                }
                for (i = 1; i <= m; i++) {
                    cin >> discount_price[i];
                    cin >> x;
                    for (j = 1; j <= x; j++) {
                        cin >> l;
                        discount_part[i][l] = 1;
                    }
                }
                cin >> l;
                for (i = 1; i <= l; i++)
                    cin >> required_part[i];
                ans = 1000000002;
                backtrack(1, 0);

                cout << "#" << tc << " " << ans << endl;
	}
	return 0;
}