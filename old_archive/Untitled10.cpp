#include<iostream>
#include<vector>
using namespace std;
int main (){
    vector<vector <int> > a;
    int n,i,j,m,x,y;
    cin>>n>>m;
    a.resize (n+2);
    for(i=1;i<=n;i++)
    {
     cin>>x>>y;
     a[x].push_back(y);                 
    }
    for(i=1;i<n;i++)
    
    cout<<a[i].size();
    if(a[i].empty()) goto l;                 
    for(j=0;j<a[i].size();j++)
    cout<<a[i][j]<<" ";
    cout<<endl;
    l:;
    return 0;
    }
