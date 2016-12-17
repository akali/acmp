#include <bits/stdc++.h>

using namespace std;

int main () {
	ifstream F ("Main.cpp");
	string s;
	int c = 0;
	while (getline (F, s))
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ')
				c++;
	cout << "C++ " << c << endl;

	F.close();

	ifstream D ("Main.java");
	c = 0;
	while (getline (D, s))
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ')
				c++;
	cout << "Java " << c << endl;
}
