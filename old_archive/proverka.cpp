#include <iostream>
using namespace std;
int x,n,i;
int a[1000];
void rec(int x)
{
if(x==n)
{for(i=1;i<=n;i++){cout<<a[i];}cout<<endl;}
else
{
a[x]=0;
rec(x+1);
a[x]=1;
rec(x+1);}}
int main(){cin>>n;rec(1);system("pause");return 0;}
