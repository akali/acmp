#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int n;
 cin>>n;
 bool b=0;
 if(n==1 || n==2 || n==3) cout<<"YES";
 else
 {
 for(int i=2;i<=sqrt(n);i++)
 {
  if(n%i==0){b=0; cout<<i<<" ";}
 }                 
 if(b=1) cout<<"YES";
 else
 cout<<"NO";
 }
 return 0;
}