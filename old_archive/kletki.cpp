#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt", "r", stdin);
 freopen("output.txt","w",stdout);
 int a;
 char b;
 cin>>b>>a;
 if((a+(b%2))%2==0) 
 cout<<"BLACK";
 else
 cout<<"WHITE";
 return 0;
}
