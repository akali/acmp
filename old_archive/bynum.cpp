#include <iostream>
#include <vector>
using namespace std;
int fact(int n)
{
 int sum=1;
 for(int i=2;i<=n;i++)
 {
  sum*=i;
 }
 return sum;
}
int main()
{    
 int n,m,perm[2222],k4[2222];
 vector<int> tperm;
 vector<int> trperm;
 cin>>n>>m;
 //for(int i=1;i<=n;i++)
 {  
 // cin>>perm[i];
 }
 
 for(int i=1;i<=n;i++)
 {
  tperm.push_back(i);
 }                
              
 for(int i=n;i>=1;i--)
 {
  k4[n-i]=m%fact(i);
  m/=fact(i);
 }

 for(int i=0;i<=n;i++)
 {
  cout<<k4[i]<<" ";
 }
 
 for(int i=1;i<=n;i++)
 {
   trperm.push_back(tperm[k4[i]]);
   tperm.erase(tperm.begin()+k4[i]);
 }
 n=trperm.size();
 for(int i=1;i<=n;i++)
 {
  cout<<trperm[i];
 }
 return 0; 
}