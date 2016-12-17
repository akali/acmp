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

const int MaxN = (int)(1e6);

int take (int x) {
	int res = 0;
	for (int i = 1; i + i <= x; i++)
		if (x % i == 0)
			res += i;
	return res;
}

bool used[MaxN];

pair <int, int> d[40];

int main () {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
	d[0] = make_pair (220, 284);
	d[1] = make_pair (1184, 1210);
	d[2] = make_pair (2620, 2924);
	d[3] = make_pair (5020, 5564);
	d[4] = make_pair (6232, 6368);
	d[5] = make_pair (10744, 10856);
	d[6] = make_pair (12285, 14595);
	d[7] = make_pair (17296, 18416);
	d[8] = make_pair (63020, 76084);
	d[9] = make_pair (66928, 66992);
	d[10] = make_pair (67095, 71145);
	d[11] = make_pair (69615, 87633);
	d[12] = make_pair (79750, 88730);
	d[13] = make_pair (100485, 124155);
	d[14] = make_pair (122265, 139815);
	d[15] = make_pair (122368, 123152);
	d[16] = make_pair (141664, 153176);
	d[17] = make_pair (142310, 168730);
	d[18] = make_pair (171856, 176336);
	d[19] = make_pair (176272, 180848);
	d[20] = make_pair (185368, 203432);
	d[21] = make_pair (196724, 202444);
	d[22] = make_pair (280540, 365084);
	d[23] = make_pair (308620, 389924);
	d[24] = make_pair (319550, 430402);
	d[25] = make_pair (356408, 399592);
	d[26] = make_pair (437456, 455344);
	d[27] = make_pair (469028, 486178);
	d[28] = make_pair (503056, 514736);
	d[29] = make_pair (522405, 525915);
	d[30] = make_pair (600392, 669688);
	d[31] = make_pair (609928, 686072);
	d[32] = make_pair (624184, 691256);
	d[33] = make_pair (635624, 712216);
	d[34] = make_pair (643336, 652664);
	d[35] = make_pair (667964, 783556);
	d[36] = make_pair (726104, 796696);
	d[37] = make_pair (802725, 863835);
	d[38] = make_pair (879712, 901424);
	d[39] = make_pair (898216, 980984);
	int l, r; cin >> l >> r;
	bool is = false;
	for (int i = 0; i <= 39; i++) {
		if (d[i].first >= l && d[i].second <= r) {
			is = true;
			cout << d[i].first << " " << d[i].second << endl;
		}
	}
	if (!is)
		cout << "Absent";

	return 0;
}
