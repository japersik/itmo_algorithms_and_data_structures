#include <iostream>
#include <cmath>

using namespace std;
int table[512][512];

void paint(int x, int y, int i, int j, int n) {
    static int c;
    ++c;
    n = n / 2;
    if ((x - j) >= n && (y - i) >= n) {
        table[i + n - 1][j + n - 1] = c;
        table[i + n][j + n - 1] = c;
        table[i + n - 1][j + n] = c;
        if (n>1){
        paint(j + n - 1, i + n - 1, i, j, n);
        paint(j + n, i + n - 1, i, j + n, n);
        paint(x, y, i + n, j + n, n);
        paint(j + n - 1, i + n, i + n, j, n);
        }
    } else if ((x - j) >= n && (y - i) < n) {
        table[i + n - 1][j + n - 1] = c;
        table[i + n][j + n - 1] = c;
        table[i + n][j + n] = c;
        if (n>1){
        paint(j + n - 1, i + n - 1, i, j, n);
        paint(x, y, i, j + n, n);
        paint(j + n, i + n, i + n, j + n, n);
        paint(j + n - 1, i + n, i + n, j, n);
        } 
    } else  if ((x - j) < n && (y - i) < n) {
        table[i + n - 1][j + n] = c;
        table[i + n][j + n - 1] = c;
        table[i + n][j + n] = c;
        if (n>1){
        paint(x, y, i, j, n);
        paint(j + n, i + n - 1, i, j + n, n);
        paint(j + n, i + n, i + n, j + n, n);
        paint(j + n - 1, i + n, i + n, j, n);
        }
    } else if ((x - j) < n && (y - i) >= n) {
        table[i + n - 1][j + n - 1] = c;
        table[i + n][j + n] = c;
        table[i + n - 1][j + n] = c;
        if (n>1){
        paint(j + n - 1, i + n - 1, i, j, n);
        paint(j + n, i + n - 1, i, j + n, n);
        paint(j + n, i + n, i + n, j + n, n);
        paint(x, y, i + n, j, n);
        }
    }
    return;
}

int main() {
    int n, x, y;
    cin >> n >> y >> x;
    n = 1 << n;
    if ((int) (pow(n, 2) - 1) % 3 != 0) {
        cout << -1;
        return 0;
    }


    --x;
    --y;
    paint(x, y, 0, 0, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            cout << table[i][j] << " ";
        cout << endl;
    }
    return 0;
}


