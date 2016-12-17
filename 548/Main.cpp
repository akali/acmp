#include <iostream>
#include <string> 
#include <cstdio>
#include <cstdlib>
  
using namespace std; 
  
int x, y;
string a, b, res; 
  
int main () {
    freopen ("input.txt", "r", stdin); 
    freopen ("output.txt", "w", stdout); 
	
	cin >> a >> b;
	
	while (x < a.size() && y < b.size()) {
		bool sol = false;
		for (int i = 0; true; ++i) {
			if (x + i >= a.size() && y + i >= b.size()) {
				if (a[a.size() - 1] <= b[b.size() - 1]) {
					res += a[x]; x++;
					sol = true;
					break;
				} else {
					res += b[y]; y++;
					sol = true;
					break;
				}
			}
			int tX = min (int (a.size() - 1), x + i);
			int tY = min (int (b.size() - 1), y + i);
			if (a[tX] < b[tY]) {
				res += a[x]; x++;
				sol = true;
				break;
			}
			if (a[tX] > b[tY]) {
				res += b[y]; y++;
				sol = true;
				break;
			}
		}
		if (sol == false) {
			res += a[x]; x++;
		}
	}
	
	while (x < a.size()) {
		res += a[x]; x++;
	}
	
	while (y < b.size()) {
		res += b[y]; y++;
	}
	
	cout << res;
    
    return 0;
}

