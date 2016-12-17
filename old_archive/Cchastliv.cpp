#include <fstream>
#include <string>
using namespace std;
int main()
{
 ifstream cin  ("input.txt");
 ofstream cout("output.txt");
 string s;
 cin>>s;
 int q=s[0]-'0'+s[1]-'0'+s[2]-'0';
 int w=s[3]-'0'+s[4]-'0'+s[5]-'0';
 if(q==w) cout<<"YES";
 else cout<<"NO";
 return 0; 
}