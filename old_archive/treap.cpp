#include <algorithm>
#include <iostream>
#include <string.h>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <vector <int> >  vvi;
typedef vector <pair <int, int> >  vpi;
typedef queue  <pair <int, int> > qpi;

#define abs(x) ((x) > 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define MP make_pair
#define inf 7777777
#define eps (1e-7)
#define sz size()
#define S second
#define F first

struct Node
{
	int l, r;
	int x, s;
	ll y;
} T[200000];

int SZ = 1, f = 0, root;

int tmp[200000], nxy = 0;
void init ()
{
	T[0].l = T[0].r = T[0].s = T[0].x = T[0].y = 0;
	for (int i = 0; i < 100000; i++) tmp[i] = i+1;
	random_shuffle (tmp, tmp+100000);
	nxy = 0;
}
void cnt (int v) {
	if (!T[v].l && !T[v].r) T[v].s = 1;
	else if (!T[v].l) T[v].s = T[T[v].r].s + 1;
	else if (T[v].r) T[v].s = T[T[v].l].s + T[T[v].r].s + 1;
	else	 	 T[v].s = T[T[v].l].s + 1;
}
void split (int v, int x, int &l, int &r) {
	if (!v) l = r = 0;
	else if (T[v].x < x) {
		split (T[v].r, x, T[v].r, r);
		l = v;
		cnt(l);
	}else {
		split (T[v].l, x, l, T[v].l);
		r = v;
		cnt(r);
	}
	cnt(v);
}
void Merge (int &v, int l, int r) {
	if (!l || !r) v = l + r;
	else if (T[l].y > T[r].y) {
		Merge (T[l].r, T[l].r, r);
		v = l;
	}else {
		Merge (T[r].l, l, T[r].l);
		v = r;
	}
	cnt(v);
}
void add (int &v, int i)
{
	if (!v) v = i;
	else
	if (T[v].y < T[i].y)
	 split (v,T[i].x,T[i].l,T[i].r), v = i;
	else
	 add ((T[v].x > T[i].x ? T[v].l : T[v].r) , i);
	cnt(v);
}
void insert (int x, int y) {
	T[SZ].x = x;
	T[SZ].y = y;
	T[SZ].l = T[SZ].r = 0;
	nxy++;
	add (root, SZ);
	SZ++;
}
void del (int &v, int x) {
	if (T[v].x == x)
		Merge (v, T[v].l, T[v].r);
	else	del   ((T[v].x > x ? T[v].l : T[v].r), x);
	cnt(v);
}
void out (int i)
{
 if(!i) return;

 out (T[i].l);

	cout << T[i].x << " " << T[T[i].l].x << " " << T[T[i].r].x << "\n";

	out (T[i].r);
}

int main ()
{
 //freopen("input.txt", "r", stdin);
	int x, n, t;
	init();
	cin >> n;
 vpi P;
	for (int i = 0; i < n; i++)
	{
		scanf ("%d%d", &t, &x);
  P.pb(MP(x, t));
	}
	sort(P.begin(), P.end());
	for(int i = 0; i < P.size(); i++) insert(P[i].S, P[i].F);
 printf("YES\n");
 out(root);
	return 0;
}

