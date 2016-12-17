# include <string>
# include <iostream>
# include <cstdio>
using namespace std;

int sum=-1,k;

void Zh(int k)
{
 if(sum==-1)sum=k;
 else sum=(sum*10)+k;
}


int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 string s;
 int i,kol=0,j;
 cin>>s;

 if(s.length()==3 && s[0]=='4' && s[1]=='0')
 {
  for(int j = 1; j <= 40; j++)
   cout<<s[2];
  return 0;
 }
 if(s.length()==3 && s[0]=='8' && s[1]=='0')
 {
  for(int j = 1; j <= 80; j++)
  {
   cout<<s[2];
   if (j == 40) 
    cout<<endl;
  }
  return 0;
 }

 for(i=0;i<s.length();i++)
 {
  if(int(s[i]-'0')<10){Zh(int(s[i]-'0'));goto l;}
  if(sum==-1){sum=1;}

  for(int j=1;j<=sum;j++)
  {
   cout<<s[i];
   if((kol+j)%40==0 && j!=sum){cout<<endl;}
  }
  kol+=sum;
  if(kol%40==0){cout<<endl;}
  sum=-1;
  l:;
 }
 return 0;
}

