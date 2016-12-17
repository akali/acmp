#include <iostream>
#include <vector>
using namespace std;

vector<long long> a(111);

int main ()
{
 
 freopen ("input.txt","r",stdin);
 //freopen ("output.txt","w",stdout);
 
 long long int n,i=2,s=0,sum=1,j,A[111111],kol=0,o=0,BIR=1;
 
 cin>>n;
 while(i*i<=n){
    if(n % i==0)
    {
      a.push_back(i);
      n=n/i;
    }
    else i++;
 }

if(n>1){a.push_back(n);}
cout<<a.size()<<endl;
for(i=1;i<=a.size();i++)
{
  for(j=i;j<=a.size();j++)
  {
  if(a[i]==a[j]){kol++;}
  if(a[i]!=a[j]){goto l;}
  }
  l:
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