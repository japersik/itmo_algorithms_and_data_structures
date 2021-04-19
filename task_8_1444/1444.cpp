#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265;

struct point {
    float length;
    double degrees;
    int index;
};

int compare_points(const void *var1, const void *var2) {
    const point*p1 = (point*) var1;
    const point*p2 = (point*) var2;
    if (p1->degrees - p2->degrees > 1e-10) 
        return 1;
    else if (p1->degrees - p2->degrees < -1e-10) 
        return -1;
    else 
        if (p1->length > p2->length)return 1;
        else return -1;
}  


int main() {
    int n;
    short f_x,f_y,x,y;
    cin >> n >> f_x >>f_y;
    point dots[n];
    dots[0].degrees = -1;
    dots[0].length = 0;
    dots[0].index = 1;
    for (int i = 1; i < n; i ++) {
        cin >> x;
        cin >> y;
        dots[i].index = i+1;
        dots[i].length = (x - f_x)*(x - f_x)+(y - f_y)*(y - f_y);
        dots[i].degrees = atan2(y - f_y, x - f_x) * 180.0 / PI;
        if (y - f_y < 0) dots[i].degrees += 360;
    }

    qsort(dots, n, sizeof(point), compare_points);
   

    int start_point = 1;
    double max_a = dots[1].degrees - dots[n-1].degrees+360 ;
    for (int i = 1; i < n - 1; i ++) {
        if (dots[i + 1].degrees - dots[i].degrees > max_a) {
            max_a = dots[i + 1].degrees - dots[i].degrees;
            start_point = i+1;
        }
    }
    cout << n << endl << 1 << endl;

    for (int i = start_point; i < n; i ++) {
        cout << dots[i].index << endl;
    }
    for (int i = 1; i < start_point; i ++) {
        cout << dots[i].index << endl;
    }
    
    return 0;
}