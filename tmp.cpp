/*
	Coded by nahzrE
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
 
using namespace std;
 
const int maxP = 50;
int maxss = 0;
vector <bool> kk (maxP);
map <int, int> l;
 
int gcd(int r1, int r2){
    return (r2 ? gcd (r2, r1 % r2) : r1);
}
 
long long lcm(int a, int b) {
    return (a / gcd(a, b) ) * (long long)b;
}
 
void merge (map <int, int> &dst, int v, int s){
    map <int, int>::iterator i = dst.find(v);
    if (i == dst.end() )
        dst[v] = s;
    else    {
         int n = i -> second + s;
         if (n)
             i -> second = n;
         else
            dst.erase(i);
    }
}
 
int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        kk [p - 1] = kk [p - 1] ^ 1;
    }
    for (int i = 0; i < maxP; i++)
        if (kk[i]){
            int p = i + 1;
            map <int, int> r (l);
            for (map <int, int> :: iterator i = l.begin(); i != l.end(); ++i){
                long long v = lcm (i -> first, p);
                if (v <= n)
                merge (r, (int) v, -2 * i -> second);
            }
            swap (l, r);
            merge (l, p, 1);
        }
  
    long long result = 0ll;
  
    for (map <int, int> :: iterator i = l.begin(); i != l.end(); ++i)
        result += (n / i -> first) * i -> second;
    cout << result;
    return 0;
}