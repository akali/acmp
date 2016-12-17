/**************************************************
  *  _  _    ____  __    ____  ____    __   _  _  *
  * ( \( )  ( ___)(  )  (_  _)(  _ \  /__\ ( \/ ) *
  *  )  (    )__)  )(__  _)(_  ) _ < /(__)\ \  /  *
  * (_)\_)()(____)(____)(____)(____/(__)(__)(__)  *
  *                                               *
  *************************************************/
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <cmath>  
#include <map>  
#include <string>
#include <cstring>  
#include <cstdio>  
#include <set>  
#include <deque>  
#include <queue>  
#include <iomanip>
#define ll long long  
#define Inf 1000 * 1000 * 1000  
#define F first  
#define S second  
#define MP make_pair  
#define ull unsigned ll  
#define len length()  
#define Pb push_back 
#define pob pop_back 
#define pof pop_front 
#define Pf push_front 
using namespace std;
ull n, m, a[10];
bool b;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n >> m;
	a[1] = 6;
	a[2] = 28;
	a[3] = 496;
	a[4] = 8128;
	a[5] = 33550336;
	a[6] = 8589869056;
	a[7] = 137438691328;
	a[8] = 2305843008139952128;
	for(int i = 1;  i <= 8; i ++)
		if(n >= a[i] && a[i] <= m){
			b = 1;
			cout << a[i] << endl;
		}
	if(b == 0)
		cout << "Absent";
	return 0;
}
