#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

int main ()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int a, b;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		set<int> q, w;
		cin >> a >> b;
		if (a < b) swap (a, b);
		
		while (a)
		{
			q.insert(a % 10);
			a /= 10;
		}
		while (b)
		{
			w.insert(b % 10);
			b /= 10;
		}
		if (q == w)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		l:;
	}
}
