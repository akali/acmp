#include <iostream>
#include <cmath>
using namespace std;

int main()
{
 int n,c=0;
 cin>>n;
 for(int i = 0;i*i<=n;i++)
 {
  if(i%2 && i%3 && i%5) c++;
 }
 cout<<c+1;
 return 0;
}