#include <iostream>
using namespace std;
int main(){
    /*ifstream cin("isprime.in");
    ofstream cout("isprime.out");*/
    int n;
    cin>>n;
    if(n==1 || n==2 || n==3) cout<<"True";
    else  
    for(int i=3; i<n; i++){
    if(n%i==0)
    cout<<"False";
    else cout<<"True";
    return 0;
}
system ("pause");
return 0;
}

