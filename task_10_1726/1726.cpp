#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    long long n, sum = 0;
    cin >> n;
    long long x[n];
    long long y[n];
    for (long long i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x,x+n);
    sort(y,y+n);
    for (long long i = 1; i < n; i++) sum += (((x[i] - x[i-1]) + (y[i] - y[i-1])) * (n-i) * i) * 2;
    sum = sum / (n * (n - 1));
    cout << sum << endl;
    return 0;
}