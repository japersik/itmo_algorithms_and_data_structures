#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

struct Point {
    int x;
    int y;
    int number;
    double tang;
};

bool compare_angle(Point p1, Point p2) { return p2.tang > p1.tang; }

int main() {
    int n;
    cin >> n;
    Point points[n];
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].number = i + 1;
        if (points[i].x < points[minIndex].x)
            minIndex = i;
    }
    int min_x = points[minIndex].x;
    int min_y = points[minIndex].y;
    for (int i = 0; i < n; i++) {
        points[i].x = points[i].x - min_x;
        points[i].y = points[i].y - min_y;
        if (points[i].x == 0 ) {
            if (points[i].y > 0) {points[i].tang = numeric_limits<double>::max();}
            else if (points[i].y < 0) {points[i].tang = numeric_limits<double>::lowest()+0.000000001;}
            else if (points[i].y == 0) {points[i].tang = numeric_limits<double>::lowest();}
        }
        else points[i].tang = ((double)points[i].y)/((double) points[i].x);

    }
    sort(points, points+n, compare_angle);
 
    cout << minIndex+1<< " " << points[n / 2].number << endl;
    return 0;
}