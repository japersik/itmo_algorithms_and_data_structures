#include <iostream>

using namespace std;

struct Interval {
    unsigned int left, right;
};

Interval ballss[50000];
Interval * balls = ballss;
int main() {
    int n;
    cin >> n;
    unsigned int time = 0, take_ball;
    while (--n >= 0) {
        cin >> take_ball;
        if (take_ball > time) {
            if (take_ball > time + 1) {
                (++balls)->left = time + 1;
                balls->right = take_ball - 1;
                time = take_ball;
            } else 
                ++time;
        } else {
            if (take_ball != balls->right) {
                cout << "Cheater";
                return 0;
            }
            if (--balls->right < balls->left) --balls;
        }
    }
    cout << "Not a proof";
    return 0;
}
