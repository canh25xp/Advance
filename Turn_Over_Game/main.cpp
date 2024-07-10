#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int ans;
int mat[4][4];

int Check();
void TurnOver(int x);
void BackTracking(int pos, int d);

int main() {
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    char s[4][4];
    for (int tc = 0; tc < T; tc++) {
        for (int i = 0; i < 4; i++)
            cin >> s[i];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i][j] == 'b')
                    mat[i][j] = 1;
                else
                    mat[i][j] = -1;
            }
        }
        ans = 100000001;
        BackTracking(0, 0);

        cout << "Case #" << tc+1 << endl;
        if (ans == 100000001)
            cout << "impossible" << endl;
        else 
            cout << ans << endl;
    }
    return 0;
}

int Check() {
    int tmp = mat[0][0];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (mat[i][j] != tmp)
                return 0;

    return 1;
}

void TurnOver(int x){
    int i = x / 4;
    int j = x % 4;
    mat[i][j] *= -1;
    if (i + 1 < 4) 
        mat[i + 1][j] *= -1;

    if (i - 1 >= 0) 
        mat[i - 1][j] *= -1;

    if (j + 1 < 4) 
        mat[i][j + 1] *= -1;

    if (j - 1 >= 0) 
        mat[i][j - 1] *= -1;
}

void BackTracking(int pos, int d) {
    int dem = d;
    if (Check()){
        if (dem < ans)
            ans = dem;
        return;
    }
    for (int x = pos; x < 16; x++){
        TurnOver(x);
        BackTracking(x + 1, dem + 1);
        TurnOver(x);
    }
}