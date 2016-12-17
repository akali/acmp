#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt", "r", stdin);
 freopen("output.txt","w",stdout);
 int n,m,d,x;
 cin>>n>>m>>x;
 d=m-n;
 cout<<n+d*(x-1); 
 return 0;
}
