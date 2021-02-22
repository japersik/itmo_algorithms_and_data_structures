#include <iostream>
using namespace std;

int main() {
    int n, pi;
    int weight = 0, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pi;
        weight += pi;
        if (weight < 0) weight = 0;
        if (weight > answer) answer = weight;
    }
    cout << answer << endl;
    return 0;
}