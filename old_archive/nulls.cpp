#include <iostream>
#include <string>
using namespace std;
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 char x;
 int n=0,maxi=0;
 string s;
 cin >> s;
 for (int i = 0 ;i < s.length();i ++  ){
 if (s[i] == '0') n ++ ;
 else n = 0;
 maxi = max (maxi, n);
 }

 cout << maxi; 

 return 0; 
}
