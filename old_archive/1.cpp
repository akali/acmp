#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
 int a[100],n,max=0;
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cin>>a[i];
 }
 //sort(a[0],a[n]);

 for(int i=0;i<n;i++)
 {
  if(a[i]>=a[i+1])
   swap(a[i],a[i+1]);
 }
 for(int i=0;i<n;i++)
 {
   if(a[i]>=a[i+1])
   swap(a[i],a[i+1]);
 }
 for(int i=0;i<n;i++)
 {
  cout<<a[i]<<" ";
 }
return 0;
}
