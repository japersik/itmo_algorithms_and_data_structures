#include <iostream>
using namespace std;
#define MAX_N 99

bool edges[MAX_N][MAX_N];
bool colors[MAX_N], colored[MAX_N];

bool paint(int n, int i, bool predColor = true) {
    if (colored[i]) return colors[i] != predColor;

    colored[i] = true;
    bool color = colors[i] = !predColor;

    for (int node = 1; node <= n; ++node) {
        if (!edges[i][node]) continue;
        if (!paint(n, node, color)) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int node;
    for (int i = 1; i <= n; ++i) {
        cin >> node;
        if (node == 0) continue;
        
        while (node > 0) {
            edges[node][i] = true;
            edges[i][node] = true;
            cin >> node;
        }
    }
    if (!paint(n,1)) {
        cout << "-1";
        return 0;
    }
    cout << noboolalpha;
    for (int i = 1; i <= n; ++i) {
        cout << colors[i];
    }
    return 0;
}
