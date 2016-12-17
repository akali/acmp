#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt", "r", stdin);
 freopen("output.txt","w",stdout);
 int n;
 cin>>n;
 cout<<(n*n)-((n-1)*3+1);
 return 0;
}
