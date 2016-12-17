#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
string n;
int s,q[201],x=0,w=0;

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin>>n;
 s=n.size();

 reverse(n.begin(),n.end());

 for(int i=0; i <= s; i++) q[i]=pow(double(2.0),double(i));

 for(int i=0; i <  s; i++) x+=q[i]*(n[i]-'0');

 if(x >= 100 && x <= 999){cout<<0; return 0;}
 
 if(x<100){cout<<0;return 0;}
 cout<<x<<endl;
 l:
 if(x>999)
 {
   x=x/10;
   w++;
   goto l;
 }
 cout<<x<<" "<<w;
 return 0;
}
