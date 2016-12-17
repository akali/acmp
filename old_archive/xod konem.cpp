#include<iostream>
using namespace std;
    long long int n,m,i,j,a[300][300]={0};
int main (){
    freopen ("knight.in", "r", stdin);
    freopen ("knight.out", "w", stdout);
    cin>>n>>m;
    a[1][1]=1;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        if(a[i][j]>0){
        if(i+2<=n && j+1<=m)a[i+2][j+1]+=a[i][j];
        if(i+1<=n && j+2<=m)a[i+1][j+2]+=a[i][j];
    }}
    cout<<a[n][m];
    return 0;
}
