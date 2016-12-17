#include <iostream>
#include <string>

using namespace std;

string a,b,c;

string chk(string a,string b)
{
 if(a.size()>b.size()) return a; else 
 if(a.size()<b.size()) return b; else
                       return max(a,b);
}

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin>>a>>b>>c;
 cout<<chk(a,chk(b,c));
}
