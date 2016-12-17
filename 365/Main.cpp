#include <cstdio>
 
using namespace std;
 
int n, s[10001];
 
void rec(int ind, int sum, int val) {
	s[ind] = val;
	if(sum == n) {
		for(int i = 1; i < ind; i++) printf("%d%c", s[i], '+');
		printf("%d\n", s[ind]);
	}
	for(int i = val; i <= n - val; i++)
		if(sum + i <= n)
			rec(ind + 1, sum + i, i);
}
 
int main() {
	freopen("input.txt" ,"r", stdin);
	freopen("output.txt","w",stdout);
                 
	scanf("%d", &n);
	rec(0, 0, 1);
	return 0;
}