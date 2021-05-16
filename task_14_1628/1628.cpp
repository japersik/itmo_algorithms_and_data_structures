#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

bool compare_x(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first<b.first;
    return a.second < b.second;
}

bool compare_y(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second<b.second;
    return a.first < b.first;
}

int counter;
int main() {
    int N, M, K;
   
    cin >> N >> M >> K;
    vector<pair<int, int>> cell;
    set<pair<int, int> > S;
    int x, y;
    for (int i = 0; i < K; ++i) {
        cin >> x >> y;
        cell.push_back(make_pair(x, y));
    }


    for (int i = 1; i <= M; i++) {
        cell.push_back(make_pair(0, i));
        cell.push_back(make_pair(N + 1, i));
    }
    
    for (int i = 1; i <= N; i++) {
        cell.push_back(make_pair(i, 0));
        cell.push_back(make_pair(i, M + 1));
    }

    K += (M + N) * 2;

    sort(cell.begin(), cell.begin() + K, compare_x);
    for (int i = 0; i < K ; i++) {
        int space = cell[i + 1].second - cell[i].second;
        if (space == 2)
            S.insert(make_pair(cell[i].first, cell[i].second + 1));
        else if (cell[i].first == cell[i + 1].first && space > 2) 
            counter ++;
    }

    sort(cell.begin(), cell.begin() + K, compare_y);
    for (int i = 0; i < K; i++) {
        int space = cell[i + 1].first - cell[i].first;
        if (space == 2) {
            if (S.find(make_pair(cell[i].first + 1, cell[i].second)) != S.end())
                    counter ++;
            }
        else if (cell[i].second == cell[i + 1].second && space > 2)
            counter ++;
    }

    cout << counter << endl;

    return 0;
}
