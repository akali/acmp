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

using namespace std;

const double eps = 1e-9;

struct point {
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

point min_px (point a, point b) {
	return a.x < b.x || (abs (a.x - b.x) <= eps && a.y < b.y) ? a : b;
}
point max_px (point a, point b) {
	return a.x > b.x || (abs (a.x - b.x) <= eps && a.y > b.y) ? a : b;
}
point min_py (point a, point b) {
	return a.y < b.y || (abs (a.y - b.y) <= eps && a.x < b.x) ? a : b;
}
point max_py (point a, point b) {
	return a.y > b.y || (abs (a.y - b.y) <= eps && a.x > b.x) ? a : b;
}

double area_triangle (point a, point b, point c) {
	return 0.5 * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x); 
}

bool ccw (point a, point b, point c) {
	return area_triangle (a, b, c) > eps;
}

bool point_in_polygon (point t, vector < point > p) {
	int i, j;
	int count = 0;
	for (i = 0; i < p.size(); ++ i) {
			j = (i + 1) % p.size();
			count += (min (p[i].y, p[j].y) < t.y && t.y <= max (p[i].y, p[j].y) && ccw (min_py (p[i], p[j]), max_py (p[i], p[j]), t));
	}
	return count % 2;
}

bool point_in_box (point t, point p1, point p2) {
	return  (abs (t.x - min(p1.x, p2.x)) <= eps || min(p1.x, p2.x) <= t.x) && 
			(abs (max(p1.x, p2.x) - t.x) <= eps || max(p1.x, p2.x) >= t.x) && 
			(abs (t.y - min(p1.y, p2.y)) <= eps || min(p1.y, p2.y) <= t.y) && 
			(abs (max(p1.y, p2.y) - t.y) <= eps || max(p1.y, p2.y) >= t.y);
}

bool point_in_segment (point t, point p1, point p2) {
	double a = p2.y - p1.y;
	double b = p1.x - p2.x;
	double c = - a * p1.x - b * p1.y;
	if (abs(a * t.x + b * t.y + c) > eps) return false;

	return point_in_box (t, p1, p2);
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	vector <point> triangle;
	point t;
	for (int i = 0; i < 3; ++i) {
		point x;
		cin >> x.x >> x.y;
		triangle.push_back (x);
	}

	cin >> t.x >> t.y;
	if (point_in_polygon (t, triangle) || point_in_segment (t, triangle[0], triangle[1]) || point_in_segment (t, triangle[1], triangle[2]) || point_in_segment (t, triangle[2], triangle[0]))
		cout << "In\n";
	else
		cout << "Out\n";
	return 0;
}