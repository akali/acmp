#include <iostream>
using namespace std;

int n,i,j,a[1000]={0};

void print(int temp)
{
 for(j = 1;j < temp;j++)
  cout<<a[ j ]<<'+';
 cout<<a[ temp ]<<endl;
}

void rec(int temp , int x ,int sum)
{
 a[ temp ] = x;
 if(sum == n) print( temp );
 for(int i = x;i <= n-x;i ++)
  if(i != 0 && sum+i <= n && i != n)
   rec(temp + 1, i ,sum + i);
} 

int main()
{
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 cin>>n;
 rec(0,0,0);
 return 0;
}