#include <bits/stdc++.h>

using namespace std;

int main () {
	ofstream out ("res.cpp");
	
	for (int n = 5; n <= 20; ++n) {
		for (int x = 1; x <= n; ++x) {
			for (int y = 1; y <= n; ++y) {
				for (int x1 = 1; x1 <= n; ++x1) {
					for (int y1 = 1; y1 <= n; ++y1) {
						cerr << n << " " << x << " " << y << " " << x1 << " " << y1 << endl;
						ofstream TEST ("input.txt");
						ifstream in ("output.txt");
						TEST << n << " " << x << " " << y << " " << x1 << " " << y1 << endl;
						system ("Main.exe");
						int res; in >> res;
						out << "d[" << n << "][" << x << "][" << y << "][" << x1 << "][" << y1 << "] = " << res << endl;
						TEST.close();
						in.close();
					}
				}
			}
		}
	}
	
	return 0;
}
