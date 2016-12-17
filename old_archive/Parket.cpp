#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector < vector<long long> > d;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
	if (x == n)
		return;
	if (y >= m)
		d[x+1][next_mask] += d[x][mask];
	else
	{
		int my_mask = 1 << y;
		if (mask & my_mask)
			calc (x, y+1, mask, next_mask);
		else
		{
			calc (x, y+1, mask, next_mask | my_mask);
			if (y+1 < m && ! (mask & my_mask) && ! (mask & (my_mask << 1)))
				calc (x, y+2, mask, next_mask);
		}
	}
}


int main()
{
	cin >> n >> m;
	
	d.resize (n+1, vector<long long> (1<<m));
	d[0][0] = 1;
	for (int x=0; x<n; ++x)
		for (int mask=0; mask<(1<<m); ++mask)
			calc (x, 0, mask, 0);

	cout << d[n][0];

}
