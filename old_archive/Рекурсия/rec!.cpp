#include <iostream>

using namespace std;

int fact(int n)
{
 int i=1;
 if(n>1)
 i=(n*fact(n-1));
 else
 return 1;
 return i;
}

int main()
{
 int n;
 cin>>n;
 cout<<fact(n);
}

       