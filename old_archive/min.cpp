#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
 int n,m,a,b;
 cin>>n>>m>>a>>b;
 cout<<min(n ,min(m ,min(a,b)));
 return 0;
}