/***                                                                           
   _|_|_|                  _|                  _|      _|                  
 _|          _|_|      _|_|_|    _|_|      _|_|_|      _|_|_|    _|    _|  
 _|        _|    _|  _|    _|  _|_|_|_|  _|    _|      _|    _|  _|    _|  
 _|        _|    _|  _|    _|  _|        _|    _|      _|    _|  _|    _|  
   _|_|_|    _|_|      _|_|_|    _|_|_|    _|_|_|      _|_|_|      _|_|_|  
                                                                       _|  
                                                                   _|_|
   _|_|_|  _|                                                      
 _|        _|_|_|    _|  _|_|    _|_|    _|_|_|  _|_|      _|_|    
 _|        _|    _|  _|_|      _|    _|  _|    _|    _|  _|_|_|_|  
 _|        _|    _|  _|        _|    _|  _|    _|    _|  _|        
   _|_|_|  _|    _|  _|          _|_|    _|    _|    _|    _|_|_|

***/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

string s[111];
double speed[111];
pair <double, string> q[111];

void InputString (int i) {
	string s = "";
	char c; cin >> c;
	s += c;
	while (cin >> c) {
		s += c;
		if (c == char (34)) {
			break;
		}
	}
	::s[i] = s;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int TimeIn1, TimeIn2, TimeOut1, TimeOut2;
		char tmp3;
		InputString(i);
		cin >> TimeIn1 >> tmp3 >> TimeIn2 >> TimeOut1 >> tmp3 >> TimeOut2;
		double Time1 = double (TimeIn1 * 60 + TimeIn2);
		double Time2 = double (TimeOut1 * 60 + TimeOut2);
		double Time;
		if (Time1 < Time2) {
			Time = double (Time2 - Time1);
		} else {
			Time = double (1440 - Time1 + Time2);
		}
		speed[i] = 650 / (Time / 60);
		q[i] = make_pair (speed[i], s[i]);
	}
	sort (q, q + n);         
	/*for (int i = 0; i < n; /|i++) {
		cout << q[i].first << " " << q[i].second << endl;
	}*/
	cout << "The fastest train is " + q[n - 1].second + ".\n";
	cout << "It's speed is " << setprecision(0) << fixed << (q[n - 1].first) << " km/h, approximately."; 
	return 0;
}
