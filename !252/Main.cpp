#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <stack>
#include <list>
#include <ctime>
#include <set>
 
using namespace std;
 
const int MaxN = (int)(1e5);

struct volume {
	int value;
	int index_value;
	string unit;
	double sort_value;

	volume(){}

} mas[MaxN];

bool operator < (const volume &a, const volume &b) {
    if (a.sort_value == b.sort_value)
    	return a.index_value < b.index_value;
	return a.sort_value < b.sort_value;
}

int main() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
 
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mas[i].value >> mas[i].unit;
		mas[i].index_value = i;
		mas[i].sort_value = mas[i].value;
		double mul = 1;
		int pos = 0;
	
		if (mas[i].unit[pos] == 'm') {
			mul = 1e-3;
			pos++;
		} else {
			if (mas[i].unit[pos] == 'k') {
				mul = 1e3;
				pos++;
			} else {
				if (mas[i].unit[pos] == 'M') {
					mul = 1e6;
					pos++;
				} else {
					if (mas[i].unit[pos] == 'G') {
						mul = 1e9;	
						pos++;
					}
				}
			}
		}
		
		if (mas[i].unit[pos] == 'p') {
			mul *= 16380;
		} else {
			if (mas[i].unit[pos] == 't') {
				mul *= 1e6;	
			} else {
				if (mas[i].unit[pos] == 'g') {
					mul *= 1;
				}
			}
		}
		mas[i].sort_value *= mul;
	}

	sort (mas, mas + n);
	
	for (int i = 0; i < n; i++)
		cout << mas[i].value << " " << mas[i].unit << endl;
 
    return 0;
}
