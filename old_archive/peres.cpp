#include <iostream>
#include <string>
using namespace std;
const int n = 4; //{ количество элементов в перестановке}
int a[n];
int index;
string s;

void generate (int l, int r)
{
 int i,v;
 if (l==r)
 {
  for (i = 1; i <= n; i ++ ) cout<<a[i]<<" ";
  cout<<endl;
 }
 else
 {
  for (i = l; i <= r ; i ++ )
  {
   v=a[l];
   a[l]=a[i];
   a[i]=v;                     //{обмен a[i],a[j]}
   generate(l+1,r);           //{вызов новой генерации}
   v=a[l]; a[l]=a[i]; a[i]=v;//{обмен a[i],a[j]}
  }
 }
}
void sp()
{
  for (int i = 1; i <= n; i ++ )
  {
   //s.push_back(a[i]);
   cout<<a[i]<<" ";
  }
  cout<<endl;
}
void rec(int p)
{
 if(p==n+1)
 {
  sp();
 }
 else
 {
  a[p]=0; rec(p+1);
  a[p]=1; rec(p+1);
 }
}

int main()
{
 //for (index = 1 ; index < n ; index ++ ) a[index]=index;
 //generate( 1,n );
 //cout<<endl<<endl;
 rec(1);
 return 0;
}
