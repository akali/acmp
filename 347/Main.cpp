#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
 
using namespace std;
int n;
vector <int> mas(5);
vector<int> met(15);

void isImpossible() {   
    if (*max_element(met.begin(),met.end())==5) {
    	cout<<"Impossible";
    	exit (0);
    }
}

void isFour_of_a_Kind() {
    if (*max_element(met.begin(),met.end())==4) {
    	cout<<"Four of a Kind";
    	exit (0);
    }
}

void isFull_House() {
    if ((mas[0] == mas[2] && mas[3] == mas[4]) || (mas[0] == mas[1] && mas[2] == mas[4])) {
    	cout << "Full House";
    	exit (0);
    }
}
void isStraight() {
    for (int i=1;i<mas.size();i++) {
        if (mas[i]!=mas[i-1]+1)
            return;
    }
	cout << "Straight";    
	exit (0);
}
void isThree_of_a_Kind() {
    if (*max_element(met.begin(),met.end())==3) {
		cout<<"Three of a Kind";
		exit (0);    	
    }
}
void isTwo_Pairs() {
    int c = 0;
    for (int i=0;i<met.size();i++)
        if (met[i]==2)
            c++;
    if (c == 2) {
    	cout<<"Two Pairs";
    	exit (0);
    }
}
void isOne_Pair() {
    if (*max_element(met.begin(),met.end())==2) {
	    cout<<"One Pair";
	    exit (0);
    }
}
void solve() {
	isImpossible ();
    isFour_of_a_Kind ();
    isFull_House ();
    isStraight ();
    isThree_of_a_Kind ();
    isTwo_Pairs ();
    isOne_Pair ();
    cout<<"Nothing";
}
int main() {
	freopen ("input.txt", "r", stdin);
	#ifndef AKALI
		freopen ("output.txt", "w", stdout);
	#endif
    for (int i=0;i<5;i++)
        cin>>mas[i];
    sort(mas.begin(),mas.end());
    for (int i=0;i<mas.size();i++)
        met[mas[i]]++;
    solve();
    return 0;
}
