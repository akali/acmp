#include <iostream>
#include <string>
using namespace std;

bool j = false,c = false;
string s;

int main()
{

 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin>>s;
 if(s[0]>='a' && s[0]<='z')
 {
  for(i=1;i<s.length();i++)
  {
   if( isalpha(s[i]) ){continue; }
   else {goto l;}
  }
  j = true;
 } 

 l:;

 if(s[0] != '_' && s[s.size() - 1] != '_')
 {
  for(i = 0;i < s.length(); i++)
  {
   if(s[i] == '_' || islower(s[i]))
   {
    if(i != s.size() - 1)
     if(s[i] == '_' && s[i + 1] == '_')
     { 
      cerr<<"Error!";
      return 0;
     }
    continue;
   }
   else goto l2;
  }
  c = true;
  l2:;
 }

 if( c &&  j){cerr<<s;return 0;}
 if(!c && !j){cerr<<"Error!";return 0;}

 if(j)
 {
  for(i = 0; i < s.size(); i++)
  {
   if(isupper(s[i]))
   {
    cout<<"_";
    s[i] = tolower(s[i]);
   }
   cout<<s[i];
  }
 }
 else
 for(i=0;i<s.length();i++)
 {
  if(s[i] == '_')
  {
   s[i + 1] = toupper(s[i + 1]);
   goto L;
  }
  cerr<<s[i];
  L:;
 }
}
