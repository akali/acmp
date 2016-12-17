#include <iostream>
#include <vector>
using namespace std;

long long int n,i=2,sum=1,j,A[111111],kol=0;
vector <long long> a(1000);
vector <long long> x(11111);

int main()
{
 freopen ("input.txt","r",stdin);
 //freopen ("output.txt","w",stdout);
 cin>>n;

 while(i*i<=n)
 {
  if(n % i == 0)
  {
   a.push_back(i);
   n/=i;
  }
  else i++;
 }
 
 if(n>1){a.push_back(n);}
 
 for(i=1;i<=a.size();i++)
 {
   for(j=i;j<=a.size();j++)
   {
   if(a[i]==a[j]){kol++;}
   if(a[i]!=a[j]){goto l;}
   }
   l:
   x.push_back(kol);
   i=j-1;
   kol=0;
 }
 for(i=1;i<=x.size();i++)
 {
  sum*=x[i];
 }
 cout<<sum;
 return 0;
}