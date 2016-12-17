#include <iostream>
using namespace std;
int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 int n,h[1001],m[1001],hm,hm1;
 cin>>n;
 for(int i=1;i<=n;i++)
 cin>>h[i]>>m[i]; 
 if(n<=3)
 {
  for(int i=1;i<=n;i++){
  m[i]+=30;
  if(m[i]>=60){h[i]++; m[i]%=60;}
  cout<<h[i]<<" "<<m[i]<<endl;
                        }
 }
 else
 {
  for(int i=1;i<=n;i++){
  if(i==1 || i==2 || i==3)
  {
   m[i]+=30;
   if(m[i]>=60){h[i]++; m[i]%=60;}
   cout<<h[i]<<" "<<m[i]<<endl;
  }                     
  else
  {
  hm=h[i]*60+m[i];
  hm1=h[i-3]*60+m[i-3];
   if(hm>hm1)
    {
     m[i]+=30;
     if(m[i]>=60){h[i]++; m[i]%=60;}
     cout<<h[i]<<" "<<m[i]<<endl;
    }
   else
    {
     m[i]=m[i-3]+30;
     if(m[i]>=60){h[i]++; m[i]%=60;}
     cout<<h[i]<<" "<<m[i]<<endl;
    }    
   }
  }
 }
 return 0;
}