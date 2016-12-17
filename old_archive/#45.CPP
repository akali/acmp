#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool prime (int n)
{
	double S = sqrt (double(n));
	for (int i = 2; i <= S; i ++)
		if (n % i == 0) return false;
	return true;
}

string ans;
long long cur = 1;

int main ()
{
	// freopen ("output.txt", "w", stdout);
	freopen ("input.txt" , "r",  stdin);
	int n;
	cin >> n;
	if (!n)
	{
		cout << 10;
		return 0;
	}
	if (n < 10)
	{
		cout << n;
		return 0;
	}
	if (prime(n))
	{
		cout << -1;
		return 0;
	}
	while (n)
	{
		if (n < 10)
		{
			ans.push_back (n + '0');
			break;
		}
		if (prime(n))
		{
			cout << -1;
			return 0;
		}
		for (int i = 9; i > 0; i--)
		{
			if (n % i == 0)
			{
				ans.push_back (i + '0');
				n /= i;
				// cout << i << " " << n << endl;
				break;
			}
		}
	}
	reverse (ans.begin(), ans.end());
	cout << ans;
	return 0;
}
