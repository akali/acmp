#include <iostream>
using namespace std;

void Hanoi(int n, int a, int b, int c)
{
  if ( n > 1 )
  {
    Hanoi (n-1, a, c, b);
    cout<<a<<" -> "<<b<<endl;
    Hanoi (n-1, c, b, a);
  } 
  else
    cout<<a<<" -> "<<b<<endl;
}

int main()
{
 int a,b,c,n;
 cin>>n>>a>>b>>c;
 Hanoi(n,a,b,c);
 return 0;
}
 
