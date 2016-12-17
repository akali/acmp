#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int a,s,m=0;
    int index=-1;
    for(int i=1; i<=n; i++) {
        cin>>a>>s;
        if(s==1 && a>m) {
            m=a;
            index=i;
        }
        cout << m << " " << index << endl;
    }
    cout<<index;
    return 0;
}
