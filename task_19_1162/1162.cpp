#include <iostream>

using namespace std;

struct Edge {
    Edge * pred;
    unsigned int end;
    float rate, commission;
};

Edge * edges_node[101] {};
float this_balance[101] {};

bool hasProfit(float balance, unsigned currency) {
    if (balance <= 0) return false;
    if (this_balance[currency] != 0) return balance > this_balance[currency];
    
    this_balance[currency] = balance;
    for (Edge * edge = edges_node[currency]; edge != NULL; edge = edge->pred) 
        if (hasProfit((balance - edge->commission) * edge->rate, edge->end))
            return true;

    this_balance[currency] = 0;
    return false;
}

int main() {    
    unsigned n, m, s;
    float v;
    cin >> n >> m >> s >> v;

    unsigned a, b;
    float r_ab, c_ab, r_ba, c_ba;
    for (unsigned i = 0; i < m; ++i) {
        cin >> a >> b >> r_ab >> c_ab >> r_ba >> c_ba;
        edges_node[a] = new Edge {edges_node[a], b, r_ab, c_ab};
        edges_node[b] = new Edge {edges_node[b], a, r_ba, c_ba};
    }

    if (hasProfit(v, s)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}
