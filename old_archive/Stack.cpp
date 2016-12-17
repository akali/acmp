#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
 freopen ("input.txt" , "r" , stdin);
 //freopen ("output.txt" , "w" , stdout);
 queue <int> s;
 string str;
 int n;
 int i=0;
 cin>>str;
 while(str=="exit")
 {
  i++;
  if(str=="push" ){cin>>n; s.push(n); cout<<"ok\n";}
  int *it;
  it=&s.back();
  if(str=="pop"  ){cout<<s.back(); s.pop(); cout<<endl;}
  if(str=="back" ){cout<<s.back()<<endl;}
  if(str=="size" ){cout<<(int) s.size()<<endl;}
  if(str=="clear"){ 
  for(int i=0;i<s.size();i++)
  {
  s.pop();
  }
  s.pop();
  cout<<"ok\n";
  }
  cin>>str; 
}
 return 0;
}
