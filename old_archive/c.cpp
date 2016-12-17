#include <bits/stdc++.h>

using namespace std;

int main () {
	ifstream cin ("tmp.txt");
	string s; cin >> s;
	
	system ("del Temp.exe");
	system (("g++ " + s + " -o Temp.exe").c_str());
	system ("Temp.exe");

	return 0;
}
