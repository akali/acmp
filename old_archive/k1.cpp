#include <cmath>
#include <iostream>
using namespace std;
int main(){
    freopen ()
long long int n, m, k=0, a[10000], b[10000], d[10000];
cin>>n;
a[5]=1;
a[6]=2;
a[7]=5;
for(int i=8; i<=n; i++){
a[i]=(a[i-1]*2)+a[i-2];
}
cout<<a[n]<<" ";
d[4]=3;
d[5]=7;
for(int i=5; i<=n; i++){
d[i]=a[i]+(d[i-1]*2);
}
cout<<d[n]<<" ";
b[1]=9;
b[2]=26;
b[3]=75;
for(int i=4; i<=n; i++){
b[i]=(b[i-1]+b[i-2]+b[i-3])*2-d[i];
}
cout<<b[n];
return 0;
}
