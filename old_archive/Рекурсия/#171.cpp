#include <iostream>
using namespace std;

long long int a[1111],n,i=2,s=0,j=0,A[12345678],c=0,o=0,S=0;
int main ()
{
 freopen ("input.txt","r",stdin);
 freopen ("output.txt","w",stdout);
 cin>>n;
 
 while(i*i<=n)
 {
  if(n % i==0)
  {
   a[++s]=i;
   n/=i;
  }
  else i++;
 }

 if(n>1){a[++s]=n;}
 
 for(i=1;i<=s;i++)
 {
  c=0;
  for(j=i;j<=s;j++)
  {
   if(a[i]==a[j]){c++;}
   if(a[i]!=a[j]){goto l;}
  }
  l:
  A[++o]=c;
  i=j-1;
 }
 S++;
 for(i=1;i<=o;i++) S*=(A[i]);
 
 cout<<S;
 return 0;
}

