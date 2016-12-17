#include <queue>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <fstream>
#include <climits>
#include <ctime>
#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// јлгоритмы дл€ работы с вычислительной геометрией

const double eps = 1e-8;
const double pi = 3.14159265358979323;
// наибольший общий делитель двух чисел
long long gcd (long long a, long long b) {
    a = (a < 0 ? - a : a);
    b = (b < 0 ? - b : b);
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}

class point {
public: 
    double x, y;
    int i;
    point(double _x, double _y)  {
        x = _x;
        y = _y;
    }
    point() {
        point(0, 0);  
    }
};

class line {
public: 
    double a, b, c;
    line(double _a = 0, double _b = 0, double _c = 0) {
        a = _a;
        b = _b;
        c = _c;
    }
};
bool point_in_box (point t, point p1, point p2)
{
    return  (abs (t.x - min(p1.x, p2.x)) <= eps || min(p1.x, p2.x) <= t.x) && 
            (abs (max(p1.x, p2.x) - t.x) <= eps || max(p1.x, p2.x) >= t.x) && 
            (abs (t.y - min(p1.y, p2.y)) <= eps || min(p1.y, p2.y) <= t.y) && 
            (abs (max(p1.y, p2.y) - t.y) <= eps || max(p1.y, p2.y) >= t.y);
}

line toline (point p1, point p2) {
    double a = p2.y - p1.y;
    double b = p1.x - p2.x;

    return line(a, b, - a * p1.x - b * p1.y);
}

int point_in_line (line l, point p) {
    double s = l.a * p.x + l.b * p.y + l.c;
    return s < - eps ? - 1 : s > eps ? 1 : 0;
}

bool is_cross_segment (point p1, point p2, point p3, point p4)
{
    line l1 = toline(p1, p2);
    line l2 = toline(p3, p4);
    int sign1 = point_in_line(l1, p3) * point_in_line(l1, p4);
    int sign2 = point_in_line(l2, p1) * point_in_line(l2, p2);

    if (abs(sign1) <= eps && abs(sign2) <= eps)
        return point_in_box (p1, p3, p4) || point_in_box (p2, p3, p4) ||
               point_in_box (p3, p1, p2) || point_in_box (p4, p1, p2);
    return sign1 <= eps && sign2 <= eps;
}

void input (point &a) {
	cin >> a.x >> a.y;
}

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif

	point a, b, c, d;
	input (a);
	input (b);
	input (c);
	input (d);

	if (is_cross_segment (a, b, c, d)) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	
	return 0;
}
