#include <bits/stdc++.h>

using namespace std;

int main () {
	
	string s;
	cin >> s;
	ifstream Main ("Main.cpp");
	ofstream file ((s + ".cpp").c_str());
	while (getline (Main, s)) {
		file << s << endl;
	}
	ofstream tmp ("tmp.txt");
	tmp << s;
	system ("g++ c.cpp -o c.exe");
	
	return 0;
}