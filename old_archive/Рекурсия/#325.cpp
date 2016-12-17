#include <iostream>

using namespace std;
int c=0;
int rec(char f, int fi, char s, int si)
{
 if(f==s && fi==si){return c;}

 if(f+1==s)
  if(fi+2==si)
   c++,rec(f+1,fi+2,s,si);
 
 else
 if(f+2==s)
  if(fi+1==si)
   c++,rec(f+2,fi+1,s,si);
 
 else
 if(f-1==s)
  if(fi-2==si)
   c++,rec(f-1,fi-2,s,si);
 
 else
 if(f-2==s)
  if(fi-1==si)
   c++,rec(f-2,fi-1,s,si);
 else
 {
  rec(f+1,fi+2,s,si);
  rec(f+2,fi+1,s,si);
  rec(f-1,fi-2,s,si);
  rec(f-2,fi-1,s,si);  
 }
}

int main()
{
 char f,s,t;
 int fi,si;
 cin>>f>>fi>>t>>s>>si;
 rec(f,fi,s,si);
 return 0;
}