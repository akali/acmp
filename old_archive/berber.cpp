#include <iostream>
using namespace std;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
 int n,h[1001],m[1001],hm=0,hm1=0,hm2=0,hm3=0;
 cin>>n;
 for(int i=1;i<=n;i++)
 {
  cin>>h[i]>>m[i];
 }
 if(n<=3){
 for(int i=1;i<=n;i++)
 {
  if(m[i]+30<60) cout<<h[i]<<" "<<m[i]+30<<endl;
  else
  if(m[i]+30>=60) cout<<h[i]+1<<" "<<(m[i]+30)%60<<endl;
 }
 }
 else
 for(int i=1;i<=n;i++)
 {
   hm=h[i]*60+m[i];
   hm1=h[i-3]*60+m[i-3];
   hm2=h[i-3]*60+m[i-3];
   hm3=h[i-3]*60+m[i-3];
  if(i==1 || i==2 || i==3)
  {
  m[i]+=30;
  if(m[i]>=60){h[i]++; m[i]+=30; m[i]%=60;}
  cout<<h[i]<<" "<<m[i]%60<<endl;
  }
  else
  if(i%3==1)
  {
   if(hm1<hm)
   {
    if(m[i]+30<=60) cout<<h[i]<<" "<<m[i]+30<<endl;
  	else
  	if(m[i]+30>60) cout<<h[i]+1<<" "<<(m[i]+30)%60<<endl;
   }
   else
   if(hm1>hm)
   {
    int q=hm+30+abs(hm1-hm);                      
    h[i]=q/60;
    m[i]=q%60;
    cout<<h[i]<<" "<<m[i]<<endl;
   }
  }
  /**************************/
  else
  if(i%3==2)
  {
   if(hm2<hm)
   {
    if(m[i]+30<=60) cout<<h[i]<<" "<<m[i]+30<<endl;
  	else
  	if(m[i]+30>60) cout<<h[i]+1<<" "<<(m[i]+30)%60<<endl;
   }
   else
   if(hm2>hm)
   {
    int q=hm+30+abs(hm2-hm);                      
    h[i]=q/60;
    m[i]=q%60;
    cout<<h[i]<<" "<<m[i]<<endl;
    //cout<<hm2<<" "<<hm;
   }
  }
  /**************************/
  else
  if(i%3==0)
  {
   if(hm3<hm)
   {
    if(m[i]+30<=60) cout<<h[i]<<" "<<m[i]+30<<endl;
  	else
  	if(m[i]+30>60) cout<<h[i]+1<<" "<<(m[i]+30)%60<<endl;
   }
   else
   if(hm3>hm)
   {
    int q=hm+30+abs(hm3-hm);                      
    h[i]=q/60;
    m[i]=q%60;
    cout<<h[i]<<" "<<m[i]<<endl;
   }
  }
  /**************************/
 }
 return 0;
}
