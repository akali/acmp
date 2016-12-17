#include <iostream>
#include <string>
using namespace std;
int n,i,k,j,sum=0,N,M,A[1000],B[1000],NM;
string a[333],x,c;
main()
{
 //freopen("input.txt","r",stdin);    freopen("output.txt","w",stdout);    
 cin >> n >> k;    a[0]='1';    for(i=1;i<=k;i++)    {        a[i]='0';        for(j=(i-n<0 ? 0 : i-n);j<i;j++){        N=a[i].length();M=a[j].length();        x=a[i];c=a[j];        NM=max(N,M);        for(int Q=0;Q<NM;Q++){A[Q]=0;B[Q]=0;}        for(int y=0;y<N;y++){A[y]=x[N-y-1]-'0';}        for(int y=0;y<M;y++){B[y]=c[M-y-1]-'0';}     int c=0,j;     a[i]="";     for(int Q=0;Q<NM;Q++)     {         c+=A[Q]+B[Q];         A[Q]=c%10;         c/=10;     }    if(c>0){NM++;A[NM-1]=1;}    for(int Q=NM-1;Q>=0;Q--)    {     if(A[Q]==9)a[i]+='9';     else if(A[Q]==8)a[i]+=+'8';     else if(A[Q]==7)a[i]+='7';     else if(A[Q]==6)a[i]+='6';     else if(A[Q]==5)a[i]+='5';     else if(A[Q]==4)a[i]+='4';     else if(A[Q]==3)a[i]+='3';     else if(A[Q]==2)a[i]+='2';     else if(A[Q]==1)a[i]+='1';     else if(A[Q]==0)a[i]+='0';    }}}cout<<a[k];}