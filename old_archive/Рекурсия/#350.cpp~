#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string a;
int n;
void in()
{
 cin>>a;
 n=a.size(); 
}

void solve()
{
 sort(a.begin(),a.end());
 do
 {
  cout<<a<<endl;
 }while (next_permutation(a.begin() , a.end()));
}
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 in();
 solve();
 return 0;
}
