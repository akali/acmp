#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    vector <int> a;
    vector <int> b;
    typedef vector<int> lnum;
    string s,s1;
    int n,i,x[100];
    cin>>s>>s1;
    const int base = 1000*1000*1000;
    for (int i=(int)s.length(); i>0; i-=9)
    {
    if (i < 9)
	a.push_back (atoi (s.substr (0, i).c_str()));
	else
	a.push_back (atoi (s.substr (i-9, 9).c_str()));
    }
    while (a.size() > 1 && a.back() == 0){a.pop_back();}
    for (int i=(int)s1.length(); i>0; i-=9)
    {
    if (i < 9)
	b.push_back (atoi (s1.substr (0, i).c_str()));
	else
	b.push_back (atoi (s1.substr (i-9, 9).c_str()));
    }
    while (b.size() > 1 && b.back() == 0){b.pop_back();}

    //---------------------------------------------------------------------------------------

    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i)
{
	if (i == a.size())
	a.push_back (0);
	a[i] += carry + (i < b.size() ? b[i] : 0);
	carry = a[i] >= base;
	if (carry)  a[i]-= base;
}
cout<<a[0];
    return 0;
}
