#include <iostream>
#include <cstdio>

using namespace std;

int n, k, ans;
string s;

void rec (int dots, int trees)
{
	if (dots + trees == n)
	{
		ans++;
		cout << s << endl;
		return;
	}
	if (dots + trees > n)
		return;
	s += '.';
	rec (dots + dots, trees + 1);
	s += 'T';
//	rec (dots, trees + 1);
}

int main ()
{
//	freopen ("out.txt", "w", stdout);
	cin >> n >> k;
	int t = 0;
	cout << "CHK One\n";
	rec (0, 0);
	cout << ans;
	return 0;
}
