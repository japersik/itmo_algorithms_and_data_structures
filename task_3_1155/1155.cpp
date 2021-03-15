#include <iostream>

using namespace std;

struct Point{
    char ch;
    int n;
};

void minus_p(Point* x, Point* y) {
    --(x->n);
    --(y->n);
    cout << y->ch << x->ch << '-' << endl;
};

void plus_p(Point* x, Point* y) {
    ++(x->n);
    ++(y->n);
    cout << y->ch << x->ch << '+' << endl;
};

int main() {
    Point a = {'A'}, b = {'B'}, c = {'C'}, d = {'D'}, e = {'E'}, f = {'F'}, g = {'G'}, h = {'H'};
    cin >> a.n >> b.n >> c.n >> d.n >> e.n >> f.n >> g.n >> h.n;
    if (a.n + c.n + f.n + h.n != b.n + d.n + e.n + g.n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    while (a.n + c.n + f.n + h.n > 0) {
        if (a.n > 0) {
            if (b.n > 0) minus_p (&a, &b);
            else if (d.n > 0) minus_p(&a, &d);
            else if (e.n > 0) minus_p(&a, &e);
            else if (g.n > 0) {
                plus_p(&f,&b);
                minus_p (&a, &b);
            }
        }
        else if (h.n > 0) {
            if (g.n > 0) minus_p(&h, &g);
            else if (e.n > 0) minus_p(&h, &e);
            else if (d.n > 0) minus_p(&h, &d);
            else if (b.n > 0) {
                plus_p(&d,&c);
                minus_p(&h, &d);
            }
        }
        else if (f.n > 0) {
            if (b.n > 0) minus_p(&f, &b);
            else if (e.n > 0) minus_p(&f, &e);
            else if (g.n > 0) minus_p(&f, &g);
            else if (d.n > 0) {
                plus_p(&a,&b);
                minus_p(&f, &b);
            }
        }
        else if (c.n > 0) {
            if (g.n > 0) minus_p(&c, &g);
            else if (d.n > 0) minus_p(&c, &d);
            else if (b.n > 0) minus_p(&b, &c);
            else if (e.n > 0) {
                plus_p(&f,&b);
                minus_p(&b, &c);
            }
        }
    }
    return 0;
}