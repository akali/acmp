#include <iostream>
#include <string>
#include <stack>
using namespace std;
const int n = 4; //{ количество элементов в перестановке}
int a[n], index;
string s;
stack< char > st;

void sp()
{
  for (int i = 0; i < n; i ++ )
  {
   s.push_back(a[i]);
  }
}
string chg(string s)
{
    for(int i=0;i<=n;i++)
    {
     if(s[i]=='0') s[i]='(';
     else
     if(s[i]=='1') s[i]=')';
    }
 return s;
}
bool chk(string s)
{
 bool q=0;
 for (int i = 0; i <= s.length(); i++)
 {
  if ( s[i] == '0'){st.push(s[i]);}
        else {if ( st.empty() || (s[i] == '1' && st.top() == '0' ) ){q = false;}  st.pop();}
  }
   q = st.empty();
}

void rec(int p)
{
 if(p==n+1)
 {
  sp();
  //cout<<s<<endl;
  //cout<<chg(s)<<endl;
 bool q=0;
 for (int i = 0; i <= s.length(); i++)
 {
  if ( s[i] == '0'){st.push(s[i]);}
  else {if ( st.empty() || (s[i] == '1' && st.top() == '0' ) ){q = false;}  st.pop();}
 }
 q = st.empty();
 if(q == 0) cout<<chg(s)<<endl;
 }
 else
 {
  a[p]=0; rec(p+1);
  a[p]=1; rec(p+1);
 }
}

int main()
{
 rec(1);
 return 0;
}
