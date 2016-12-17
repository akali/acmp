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

long long n;
vector <long long> a;
	
int main () {
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
		
	cin >> n;
		
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			a.push_back (i);
			n /= i;
		}
	}
	
	if (n > 1)
		a.push_back (n);
		
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";
	
	long long S = 1;
	
	for (int i = 0; i < a.size(); ++i) {
		long long c = 0;
		int k = a[i];
		for (; i < a.size(); ++i) {
			c += k == a[i];
			if (k != a[i])
				break;
		}
		S *= (c + 1);
	}
	cout << S;
	return 0;
}