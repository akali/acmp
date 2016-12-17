#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream> 
 
using namespace std;

const int   arabar[]  = {  1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000};
const char *romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
char A[20], B[20];
int szA, szB;

void pushA (char q) {
	A[szA++] = q;
}

void pushB (char q) {
	B[szB++] = q;
}
 
char *arab2roman (unsigned short int arab) {
	static char roman[80];
	const int m = sizeof(arabar)/sizeof(int)-1, arabmax=arabar[m];
	const char romanmax = romanar[m][0];
	int i, n;
	if(!arab) {
		*roman=0;
		return roman;
	}
	i=0;
	while(arab>arabmax) {
		roman[i++] = romanmax;
		arab      -= arabmax;
	}
	n=m;
	while(arab > 0) {
		if(arab >= arabar[n]) {
			roman[i++] = romanar[n][0];
			if(n&1)
				roman[i++] = romanar[n][1];
			arab -= arabar[n];
		} else
			n--;
	}
	roman[i]=0;
	return roman;
}
 
unsigned short int roman2arab(char *roman) {
	const int m = sizeof(arabar)/sizeof(int)-1;
	unsigned short int arab;
	int len, n, i, pir;
	len=strlen(roman);
 
	arab=0;
	n=m;
	i=0;
	while(n >= 0 && i < len) {
		pir=n&1;
		if(roman[i] == romanar[n][0] && (!pir || roman[i+1] == romanar[n][1])) {
			arab += arabar[n];
			i    += 1+pir;
		} else
			n--;
	}
	return arab;
}

int main () {
	freopen ("input.txt", "r", stdin);
	char s[20];
	cin >> s;
	int SZ = strlen (s), i = 0;
	static unsigned short int a, b;
	bool is = true;
	while (true) {
		if (s[i] == '/') {
			a = roman2arab (A);
		}
		if (s[i] != '/' && s[i] != 'I' && s[i] != 'V' && s[i] != 'X' && s[i] != 'L' && s[i] != 'M' && s[i] != 'D' && s[i] != 'C') {
			cout << "ERROR";
			is = false;
		}
		pushA (s[i]);
	}
	if (is) {
		for (i = i + 1; i < SZ; i++) {
			if (s[i] != '/' && s[i] != 'I' && s[i] != 'V' && s[i] != 'X' && s[i] != 'L' && s[i] != 'M' && s[i] != 'D' && s[i] != 'C') {
				cout << "ERROR";
				is = false;
			}
			pushB (s[i]);
		}
	}
	if (is) {
		b = roman2arab (B);
		unsigned short int G = __gcd (a, b);
		cout << arab2roman (a / G) << "/" << arab2roman (b / G);
	}
	return 0;
}
