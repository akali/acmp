#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 string s;
 cin>>s;
 int i=0;
 do{
  if(i==1) {cout<<s;return 0;}
  i++;
 }while(next_permutation(s.begin(),s.end()));
 return 0;
}