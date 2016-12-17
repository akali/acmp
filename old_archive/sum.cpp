#include<iostream>
using namespace std;
int main ()
{
freopen("input.txt", "r", stdin);
freopen("output.txt","w",stdout);
int n;
cin>>n;
if(n>=1)
{
cout<<n*(n+1)/2;
}
else
{
cout<<-(n*(n-1)/2)+1;
}
return 0;
} 
