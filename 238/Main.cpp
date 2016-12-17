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
// #include <climits>
#include <ctime>
 
using namespace std;
 
const int MaxN = (int)(100), MaxH = 1000;
 
bool c[MaxN][MaxN], ex[MaxN][MaxN];
int tpa[MaxH][MaxH];
int tpb[MaxH][MaxH];
int h, k, oper;
int n, m, sa, sb;
int dx[] = {0,  0, 1, -1};
int dy[] = {1, -1, 0,  0};
 
int INF = (int)(1e3);
 
bool ok (int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m);
}
 
int solve (int x, int y) {
    queue <pair <int, int> > q;
    queue <int> D;

   	D.push (1);
    q.push (make_pair (x, y));
	 
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        int d = D.front();
        q.pop();
        D.pop();
 
        if (ex[x][y]) {
        	return d;
        }
        if (tpa[x][y] && tpb[x][y]) {
            if (!c[tpa[x][y]][tpb[x][y]]) { // d[x][y] + 1) {
                q.push (make_pair (tpa[x][y], tpb[x][y]));
                D.push (d + 1);
            }
        }
        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
 
            if (ok (X, Y)) {
                if (!c[X][Y]) {// > d[x][y] + 1) {
                    c[X][Y] = true;
                    q.push (make_pair (X, Y));
                    D.push (d + 1);
                }
            }
        }
    }
    return INF;
}
 
int main () {
    freopen ("input.txt", "r", stdin);
    #ifndef AKALI
        freopen ("output.txt", "w", stdout);
    #endif
 
    cin >> n >> m;
 
    cin >> sa >> sb;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
 
    cin >> h;
 
    for (int i = 0; i < h; i++) {
        int x, y, x1, y1; cin >> x >> y >> x1 >> y1;
        tpa[x][y] = x1;
        tpb[x][y] = y1;
    }
     
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        ex[x][y] = true;
    }
 
    int res = INF;
 
    res = min (res, solve (sa, sb));
 
    if (res == INF) {
        cout << "Impossible";
    } else {
        cout << res;
    }
    return 0;
}
