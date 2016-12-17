#include <iostream>
using namespace std;

int main ()
{

freopen ("input.txt","r",stdin);
freopen ("output.txt","w",stdout);
long long int a[100],n,i=2,s=0,sum=1,j,A[111111],kol=0,o=0,BIR=1;
cin>>n;
  while(i*i<=n){
    if(n % i==0)
    {
      s++;
      a[s]=i;
      n=n/i;
    }
    else i++;
        }
if(n>1){s++;a[s]=n;}
for(i=1;i<=s;i++)
{
  for(j=i;j<=s;j++)
  {
  if(a[i]==a[j]){kol++;}
  if(a[i]!=a[j]){goto l;}
  }
  l:;
  o++;
  A[o]=kol;
  i=j-1;
  kol=0;
}
for(i=1;i<=o;i++)
{
BIR*=A[i];
}
cout<<BIR;
}	