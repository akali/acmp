#include <iostream>
#include <vector>
using namespace std;

vector <bool> used(16000, false);

int n,a[1001];

void print(int x)
{
 for(int i=0;i<x;i++)
 {
  cout<<a[i]<<" ";
 }

 cout<<"Print"<<endl;
}

void make(int x)
{
 for(int i=x;i>=1;i--)
 {
  a[i]=i;
 }
}

void rec(int x)
{
 
 if(x==0){print(x); return;}
 
 if(!used[x])
 { 
  make(x);
  used[x]=true;
  rec(x-1);
 }
         
 used[x]=true;
 rec(x-1);
 used[x]=false;
}

int main()
{
 freopen("input.txt","r",stdin);
 cin>>n;
 rec(n);
 return 0;
}