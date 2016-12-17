#include <iostream>
using namespace std;
int main() {
    int i,j,n,c=0,m;
    cin>>m;
    for(i=1;i<=10;i++) {
        int s=0;
        for(j=1;j<i;j++) {
            if(i%j==0)
            	s+=j;
        }
        if(s==i && i==m) c=1;
        else
        c=0;
    }
    if(c==1) cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
