#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MaxN = (int)(1e5);
 
int n, m, Size = -1;
int tmp;
 
struct event {
	int type, ind, Result;
	long long num;
	bool operator < (const event &e) const {
		if (num == e.num)
			return type < e.type;
	    return num < e.num;
	}
} Events[MaxN * 3];

int main() {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
    #endif 
	cin >> n >> m;
     
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		if (l > r)
			swap (l, r);    
		Size++; Events[Size].num = l; Events[Size].type = 1; Events[Size].ind = Size;            
		Size++; Events[Size].num = r; Events[Size].type = 3; Events[Size].ind = Size;                
	} 
	for (int i = 1; i <= m; i++){
		int x; cin >> x;
		Size++; Events[Size].num = x; Events[Size].type = 2; Events[Size].ind = Size;                 
	}
     
    sort (Events, Events + Size + 1);

	for (int i = 0; i <= Size; i++) {
		if (Events[i].type == 1) tmp++;
		if (Events[i].type == 2) Events[i].Result = tmp;
		if (Events[i].type == 3) tmp--;
	}

	vector <pair <int, int> > Result;
	for (int i = 0; i <= Size; i++){
		if (Events[i].type == 2)
			Result.push_back (make_pair (Events[i].ind, Events[i].Result));
	}
	sort (Result.begin(), Result.end());
	for (int i = 0; i < Result.size(); i++)
		cout << Result[i].second << " ";
	return 0;
}
